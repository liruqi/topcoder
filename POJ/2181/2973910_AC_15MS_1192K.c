#define max(x,y) x>y?x:y
#define maxn 150001
int dp[maxn][2],n,i,t;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]-t);
		dp[i][1] = max(dp[i-1][0]+t, dp[i-1][1]);
	}
	printf("%d\n", max(dp[n][0],dp[n][1]));
}
