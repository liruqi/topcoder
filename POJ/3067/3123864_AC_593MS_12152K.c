
#include <stdio.h>
#include <string.h>
int adj[1010][1010];
int sum[1010][1010];
int sta[1010][1010];
long long solve(){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    int i,j,ec,wc;
    memset(adj,0,sizeof(adj));
    memset(sum,0,sizeof(sum));
    memset(sta,0,sizeof(sta));
    
    for(i=0;i<K;i++) {
        scanf("%d%d",&ec,&wc),
        adj[ec][wc]++;
    }
    for(i=1;i<=N;i++){
        for(j=M;j>=0;j--){
            sum[i][j]=adj[i][j+1]+sum[i][j+1];
        }
    }
    for(i=2;i<=N;i++)
        for(j=1;j<=M;j++)
            sta[i][j]=sta[i-1][j]+sum[i-1][j];
            
    long long cnt=0;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++)
            cnt+=adj[i][j]*sta[i][j];
    }
    return cnt;
}

int main(){
    int i,ks;
    scanf("%d",&ks);
    for(i=1;i<=ks;i++) 
        printf("Test case %d: %I64d\n",i,solve());
}
