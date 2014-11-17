//integer decomposition
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int f[100],e[100];
char buf[200];
int exp(int f,int e){
    int r=1;
    while(e--)
        r*=f;
    return r;
}
int main()
{
    int i, n, top;
    while(cin.getline(buf, 200) && buf[0]!='0'){
        istringstream ss(buf);
        i=0;
        while(ss>>f[i]>>e[i]){
            //cout<<f[i]<<" "<<e[i]<<endl;
            i++;
        }
        n=1; top=i;
        for(i=0;i<top;i++)
            n*=exp(f[i], e[i]);
        n--;
        
        for(top=0,i=2; i*i<=n; i++) if(n%i == 0){
            e[top]=0;
            do{
                e[top]++;
                n/=i;
            }while(n%i == 0);
            f[top]=i;
            top++;
        }
        if(n>1) {
            e[top]=1;
            f[top++]=n;
        }
        for(i=top-1;i>=0;i--)
        {
            cout<<f[i]<<' '<<e[i];
            cout<<(i==0?'\n':' ');
        }
    }
    return 0;
}
