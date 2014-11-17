#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Gangster{
	int t,p,s;
}gan;
int N,K,T,top;
gan A[110];

int dp[110][110];
bool cmp(gan a, gan b){	return a.t<b.t;}
int main(){int i,j,k;
	cin>>N>>K>>T;
	for(i=1;i<=N;i++) cin>>A[i].t;
	for(i=1;i<=N;i++) cin>>A[i].p;
	for(i=1;i<=N;i++) cin>>A[i].s;
	sort(A+1,A+N+1,cmp);
	memset(dp,0xff,sizeof(dp));
	dp[0][0]=0;
	A[0].t=0;
	for(i=1;i<=N;i++){
		for(j=0;j<i;j++)
		for(k=0;k<=K;k++)
		if(abs(A[i].t-A[j].t) >= abs(A[i].s-k))
			if(dp[j][k]>=0)
				dp[i][A[i].s] >?= dp[j][k]+A[i].p;
	}
	j=0;
	for(int i=N; i>=0; i--)
		for(k=0;k<=K;k++)
			j >?= dp[i][k];
	cout<<j<<endl;
}