#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 150001

int dp[maxn][2],n;
//0: inc ,1 dec
int main(){
	int i,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]-t);
		dp[i][1] = max(dp[i-1][0]+t, dp[i-1][1]);
	}
	printf("%d\n", max(dp[n][0],dp[n][1]));
}
