#

#define maxn 440

#include <string.h>
#include <stdio.h>
int ffn[maxn][maxn],n,k;

void adfactor(int p)
{
	int i,c=p;
	for(i=2;i*i<=c;i++)if(c%i==0){
		do{
			c/=i;
			ffn[p][i]++;
		}while(c%i==0);
	}
	if(c>1) ffn[p][c]++;
}


void init(){
	int i,j;memset(ffn[1], 0, maxn*4);

	for(i=2;i<maxn;i++){
		memcpy(ffn+i,ffn+i-1,maxn*4);
		adfactor(i);
	}
}

void solve()
{
	int i;
	long long r=1;
	for(i=2;i<=n;i++)
		r*=(1+ffn[n][i]-ffn[n-k][i]-ffn[k][i]);
	printf("%I64d\n",r);
}
int main()
{
	init();
	while(EOF!=scanf("%d%d",&n,&k))
		solve();
}

