#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1001
#define inf 0x0f0f0f0f
int N;
int A, B;
int dp[maxn*12];

int main(){
	cin>>N;
	cin>>A>>B;
	memset(dp,0x0f,sizeof(dp));
	dp[A]=0;
	dp[B]=1;
	int sum = A+B;
	for(int i=1;i<N;i++){
	 	cin>>A>>B;
	 	sum += A+B;
		for(int j=sum; j>=0; j--) if(dp[j]!=inf)
		{
			int v=dp[j];
			dp[j]=inf;
			dp[j+A] <?= v;
			dp[j+B] <?= v+1;
			
		}
	}
	int lt = (sum)/2;
	int rt = (sum+1)/2;
	for(;dp[rt]==inf && dp[lt]==inf;lt--, rt++);
	cout<<min(dp[rt],dp[lt])<<endl;
	
	cin>>N;
}
