#include <iostream>
using namespace std;
#define maxn 1001

int A[maxn],N;
int lis[maxn];

void ipt(){
    int i;
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
}
void sol(){
    int i,j,t;
    for(i=0;i<N;i++) lis[i]=1;
    for(i=1;i<N;i++)
        for(j=0;j<i;j++)
            if(A[j]<A[i])
                lis[i]>?=lis[j]+1;
}
void opt()
{
    int ml=0,i;
    for(i=0;i<N;i++){
        ml>?=lis[i];
    }
    cout<<ml<<endl;
}
int main()
{
    ipt();
    sol();
    opt();
    return 0;
}
