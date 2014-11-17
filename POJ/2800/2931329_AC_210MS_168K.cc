#include <stdio.h>
#include <math.h>
typedef long long llong;

int main(){
	llong n,k;
	scanf("%I64d%I64d",&n,&k);
	llong r=sqrt(k);
	llong b=k/r;
	llong i;
	llong sum=0;
	//printf("*%I64d\n",r);
	for(i=1; i<=b && i<=n; i++) 
		sum+=k%i;
	for(i=r;i>1;i--){
		llong s=k/i+1;
		llong e=k/(i-1);

		if(s>n)break;
		if(e>n)e=n;
		//printf("*%I64d -> %I64d\n",s,e);
		sum += (k%s + k%e)*(e-s+1)/2;
	}
	if(n>k) 
		sum += (n-k)*k;
	printf("%I64d\n",sum);
}
