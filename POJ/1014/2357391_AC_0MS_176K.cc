#include <iostream>
using namespace std;

int M[10];
bool A[100];

int ipt(){
    int i,c=0;
    for(i=1;i<=6;i++){
        cin>>M[i];    
    }
    M[1]%=12;
    if(M[2]>4) M[2]=4-M[2]%2;
    if(M[3]>5) M[3]=4+M[3]%2;
    if(M[4]>5) M[4]=4+M[4]%2;
    if(M[5]>6) M[5]=6-M[5]%2;
    if(M[6]>5) M[6]=4+M[6]%2;
    for(i=1;i<=6;i++) c+=i*M[i];
    return c;
}

bool cbd(int half){
    int i,j;
    memset(A,0,sizeof(A[0])*(half+1));
    A[0]=true;
    for(i=1;i<=6;i++){
        while(M[i]--){
            for(j=half-i;j>=0;j--)
                if(A[j])
                    A[j+i]=true;
        }
    }
    return A[half];
}

int main()
{
    int tc=1,tot;
    while(tot=ipt()){
        cout<<"Collection #"<<tc++<<":\n";
        //cout<<tot<<endl;
        puts((tot%2==0 && cbd(tot/2))?"Can be divided.":"Can't be divided.");
        puts("");
    }
    return 0;
}
