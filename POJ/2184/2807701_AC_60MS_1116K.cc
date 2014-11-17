#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 210000
#define zero (maxn/2)
#define ninf 0xf0f0f0f0
int dp[maxn],n;

int main()
{
    int i,j;
	int x,y,xmax,xmin;

    while(cin>>n){
        memset(dp, 0xf0, sizeof(dp));
		dp[zero]=0;
		xmax=zero;
		xmin=zero;
        for(i=0;i<n;i++){
			cin>>x>>y;
			if(x>=0){
				for(j=xmax;j>=xmin;j--)if(dp[j]!=ninf)
					if(dp[j+x]<dp[j]+y)
						dp[j+x]=dp[j]+y;
				xmax+=x;
			}
			else {
				for(j=xmin;j<=xmax;j++)if(dp[j]!=ninf)
					if(dp[j+x]<dp[j]+y)
						dp[j+x]=dp[j]+y;
				xmin+=x;
			}
			//for(j=xmin;j<=xmax;j++)if(dp[j]!=ninf)cout<<(j-zero)<<" - "<<dp[j]<<endl;cout<<endl;
		}
		//cout<<"range: "<<xmin<<'-'<<xmax<<endl;
		for(i=zero;i<=xmax;i++)if(dp[i]>=0){
			j=dp[i]+i-zero;
			if(dp[zero]<j) dp[zero]=j;
		}
		cout<<dp[zero]<<endl;
    }
}
