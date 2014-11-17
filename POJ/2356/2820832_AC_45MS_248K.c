#include <stdio.h>
#include <string.h>
#define maxn 10001
int A[maxn];
int L[maxn];
int main(){
    int N,i,j,s=0;
    scanf("%d",&N);memset(L,-1,4*maxn);
    for(L[0]=0,i=1;i<=N;i++){
        scanf("%d",A+i);
        s=(s+A[i])%N;
        if(L[s]>=0)
        {
            printf("%d\n",i-L[s]);
            for(j=L[s]+1; j<=i; j++)
                printf("%d\n",A[j]);
            return 0;
        }
        L[s]=i;
    }
}
