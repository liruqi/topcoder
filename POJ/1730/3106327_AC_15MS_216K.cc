#include <stdio.h>
#include <algorithm>
using namespace std;

long long i, n;
bool neg;
int getodd(int x){while(x%2==0)x>>=1;return x;}
int sol(){
	int ret=-1;
	if(n<0) n=-n, neg=1; else neg=0;
	for(i=2;i*i<=n;i++)if(n%i==0){
		int cnt=0;
		do
		cnt++,n/=i;
		while(n%i==0);
		if(ret<0) ret=cnt;
		else ret=__gcd(cnt,ret);
	}
	if(n>1) return 1;
	return neg?getodd(ret):ret;
}
int main(){
	while(~scanf("%I64d",&n)&&n)printf("%d\n",sol());
}
