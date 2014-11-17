#include <stdio.h>
#include <math.h>
typedef long long llong;
int main(){
	llong n,k,i,sum=0;
	scanf("%I64d%I64d",&n,&k);
	llong r=sqrt(k), b=k/r;
	for(i=1; i<=b && i<=n; i++) 
		sum+=k%i;
	for(i=r;i>1;i--){
		llong s=k/i+1;
		llong e=k/(i-1);
		if(s>n)break;
		if(e>n)e=n;
		sum += (k%s + k%e)*(e-s+1)/2;
	}
	if(n>k) 
		sum += (n-k)*k;
	printf("%I64d\n",sum);
}
