#include <iostream>
using namespace std;

class cake{
    public:
        int r, c;
        int cir(){
            return (r+c)*2;
        }
        int area(){
            return r*c;
        }
        cake operator=(cake c2){
            r=c2.r;c=c2.c;
        }
};

cake C[200];
int top;

void delP (int p){
    for(int i=p;i+1<top;i++)
        C[i]=C[i+1];
    top--;
}

void addP(cake ck){
    C[top]=ck;
    top++;
}

bool cmp(cake a, cake b){
    return a.area()<b.area();
}

int main()
{
    int n,w,d;
    while(cin>>n>>C[1].c>>C[1].r){
        if(C[1].c+C[1].r==0) return 0;
        top=2;
        for(int i=1;i<=n;i++)
        {
            int p,s;
            cin>>p>>s;
            cake c1=C[p];
            cake c2;
            s%=c1.cir();
            if(s<c1.c){
                c2.c = c1.c-s;
                c2.r = c1.r;
                c1.c = s;
            }
            else if(s<c1.r+c1.c){
                s-=c1.c;
                c2.r=c1.r-s;
                c2.c=c1.c;
                c1.r=s;
            }
            else if(s<c1.r+c1.c*2){
                s-=c1.r+c1.c;
                c2.c = c1.c-s;
                c2.r = c1.r;
                c1.c = s;
            }
            else {
                s-=c1.r+c1.c*2;
                c2.r=c1.r-s;
                c2.c=c1.c;
                c1.r=s;
            }
            //cout<<c1.area()<<" "<<c2.area()<<endl;
            delP(p);
            if(c1.area()<c2.area()){
                addP(c1);addP(c2);
            }
            else {
                addP(c2);addP(c1);
            }
        }
        sort(C+1,C+top,cmp);
        for(int i=1;i<top;i++){
            cout<<C[i].area();
            i+1==top?cout<<endl:cout<<" ";
        }
    }
}

