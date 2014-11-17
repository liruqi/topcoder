
#define maxe 1100000
long long E[maxe],A[maxe];
#include<iostream>
using namespace std;

void init()
{
    int i,j;
    
    for(i=1;i<maxe;i++) 
        E[i]=i;
    for(i=2;i<maxe;i++) if(i==E[i]){
        for(j=i;j<maxe;j+=i)
            E[j]=E[j]-E[j]/i;
    }

    A[1]=0;
    for(i=2;i<maxe;i++) 
        A[i]=A[i-1]+E[i];
}
int main()
{
    init();
    int n;
    while(cin>>n && n>0){
        cout<<A[n]<<endl;
    }
    return 0;
}
