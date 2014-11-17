#include <stdio.h>
int M,N,L[10010];
int dp[10010];
#define INF (int)1E9
#define sqr(x) ((x)*(x))
void solve(){
	int i,j,sum,tcs;
	//dp[0] = sqr(M-L[0]);
	for(i=1;i<=N;i++){
		sum=L[i];
		dp[i]=sqr(M-L[i]) + dp[i-1];
		for(j=i-1;j>0 && (sum=sum+L[j]+1)<=M;j--){
			tcs=sqr(M-sum) + dp[j-1];
			dp[i]<?=tcs;
		}
		//printf("%d %d \n",i,dp[i]);
	}
	printf("%d\n",dp[N]);
}
int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&M,&N);
		for(i=1;i<=N;i++)scanf("%d",L+i);
		solve();
	}
}