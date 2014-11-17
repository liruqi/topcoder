#define maxe 1100000
long long E[maxe],A[maxe];
#include<stdio.h>

void init()
{
    int i,j;
    
    for(i=1;i<maxe;i++) 
        E[i]=i;
    for(i=2;i<maxe;i++) if(i==E[i]){
        for(j=i;j<maxe;j+=i)
            E[j]=E[j]-E[j]/i;
    }
    for(i=2;i<maxe;i++) 
        A[i]=A[i-1]+E[i];
}
int main()
{
    int n;init();
    while(scanf("%d",&n)==1 && n>0){
        printf("%I64d\n",A[n]);
    }
    return 0;
}

