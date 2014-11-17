#define mx 110
int dt[mx],dp[mx][mx];
int main(){
    int N,i,j,k;
    memset(dp,0x0f,sizeof(dp));
    memset(dp,0,sizeof(dp[0]));
    scanf("%d",&N);
    for(i=0;i<N;i++)scanf("%d",dt+i);
    for(i=1;i<=N-2;i++){
        for(j=0;j+i<N-1;j++){
            for(k=0;k<i;k++){
                int tmp=dp[k][j]+dp[i-k-1][j+k+1]+dt[j]*dt[j+k+1]*dt[j+i+1];
                if(dp[i][j]>tmp)
                    dp[i][j]=tmp;
            }
            //printf("%d\t",dp[i][j]);
        }
        //puts("");
    }
    printf("%d\n",dp[N-2][0]);

}
