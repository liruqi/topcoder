#include<stdio.h>
#include <string.h>

int pn[200],top;
#define maxn 1122
int W[maxn][15];
bool prime[maxn];
void init()
{
    int i,j;
    memset(prime,1,1122);
    prime[0]=prime[1]=1;
    for(i=2;i*i<maxn;i++)if(prime[i])
    for(j=i*i;j<maxn;j+=i)
        prime[j]=0;
}

main(){
    int i, j, k, n;
    init();
    
    for(i=2;i<maxn;i++) if(prime[i]){
        for(j=maxn-1;j>1;j--)
            for(k=1;k<14;k++) if(j+i<maxn && W[j][k]){
                W[j+i][k+1]+=W[j][k];
            }
        W[i][1]=1;
    }
    while(scanf("%d%d", &n,&k)==2 && n){
        printf("%d\n",W[n][k]);
    }
}