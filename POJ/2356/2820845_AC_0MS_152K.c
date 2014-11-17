#include <string.h>
#define m 10001
int A[m],L[m],N,i,s;
main(){
    scanf("%d",&N);
    memset(L,-1,4*m);
    for(L[0]=0,i=1;i<=N;i++){
        scanf("%d",A+i);
        s=(s+A[i])%N;
        if(L[s]>=0){
            printf("%d\n",i-L[s]);
            for(;i>L[s];i--)printf("%d\n",A[i]);
            return;
        }
        L[s]=i;
    }
}
