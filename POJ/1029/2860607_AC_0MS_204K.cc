#include <stdio.h>
#include <string.h>
#define maxn 1100
int N,K,P;
int stk[2][maxn];
char L[maxn],R[maxn],T[maxn],res[10],cne;

int sol(){
    int fsc=0,i,cnt=0;
    for(i=1;i<=N;i++) if(!T[i]){
        if(L[i]==cne) cnt++,fsc=i;
        else if(R[i]==cne) cnt++,fsc=i;
        if(cnt>1)return 0;
    }
    return fsc;
}

int main(){
    scanf("%d%d",&N,&K);
    int i,j;
    for(i=0;i<K;i++){
        scanf("%d",&P);
        for(j=0;j<P;j++) scanf("%d",stk[0]+j);
        for(j=0;j<P;j++) scanf("%d",stk[1]+j);
        scanf("%s",res);
        switch(res[0]){
            case '=':
                for(j=0;j<P;j++) T[stk[0][j]]=1,T[stk[1][j]]=1;
                break;
            case '<':
                cne++;
                for(j=0;j<P;j++) L[stk[0][j]]++,R[stk[1][j]]++;
                break;
            case '>':
                cne++;
                for(j=0;j<P;j++) L[stk[1][j]]++,R[stk[0][j]]++;
                break;
        }
    }
    printf("%d\n",sol());
}
