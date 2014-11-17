#include <iostream>
using namespace std;
#define maxn 1001

int A[maxn],N;
int lis[maxn];

int ipt(){
    int i;
    if(!(cin>>N)) return 0;
    for(i=0;i<N;i++)
        cin>>A[i];
    return 1;
}
void sol(){
    int i,j,t;
    for(i=0;i<N;i++) lis[i]=1;
    for(i=1;i<N;i++)
        for(j=0;j<i;j++)
            if(A[j]<A[i])
            {
                t=lis[j]+1;
                lis[i]>?=t;
            }
}
void opt()
{
    int ml=0,i;
    for(i=0;i<N;i++){
        ml>?=lis[i];
        //cout<<lis[i]<<" ";
    }
    cout<<ml<<endl;
}
int main()
{
    while(ipt())
    {
    sol();
    opt();
    }
    return 0;
}
