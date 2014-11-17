#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int dp[100008];
int numb,cash,cash_n,dest;

#define ni(x) (scanf("%d",&x))

void solve()
{
	ni(cash_n);
	fill(dp+1,dp+dest+1,0);
	dp[0] = 1;
	for(int i=0;i<cash_n;i++)
	{
		ni(numb);
		ni(cash);
		for(int j=0;j<=dest;j++)
		{
			if(dp[j])
			{
				dp[j] = numb+1;
				continue;
			}
			int prev = j - cash;
			if(prev>=0 && dp[prev]>1)
				dp[j] = dp[prev] - 1;
		}
	}
	int ret;
	for( ret=dest; ret>=0 && dp[ret]==0; ret--);
	printf("%d\n", ret);
}

int main()
{
	while( ni(dest)!=EOF ) solve();
}
