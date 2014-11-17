#include <stdio.h>
#define sl 1010
char xs[sl],ys[sl];
int xl,yl;
int dp[sl][sl];

int main(){
	int i,j;
	
	for(i=0;i<sl;i++) 
		dp[0][i]=i,dp[i][0]=i;
	while(~scanf("%d%s",&xl,xs+1)){
	scanf("%d%s",&yl,ys+1);
	for(i=1;i<=xl;i++){
		for(j=1;j<=yl;j++)
		{
			dp[i][j]=dp[i-1][j-1]+(xs[i]==ys[j]?0:1);
			dp[i][j]<?=dp[i][j-1]+1;
			dp[i][j]<?=dp[i-1][j]+1;
			//printf("%d ",dp[i][j]);
		}
		//puts("");
	}
	printf("%d\n",dp[xl][yl]);
	}
}

