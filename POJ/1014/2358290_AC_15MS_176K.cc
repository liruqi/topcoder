#include <iostream>
using namespace std;

int M[10];
bool A[100];

int ipt(){
    int i,c=0;
    for(i=1;i<=6;i++){
        cin>>M[i];c+=i*M[i];M[i]%=12;
    }
    return c;
}

bool cbd(){
    int i,j,c=0,half;
    for(i=1;i<=6;i++){
        c+=M[i]*i;
    }
    half=c/2;
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

        puts((tot%2==0 && cbd())?"Can be divided.":"Can't be divided.");
        puts("");
    }
    return 0;
}
