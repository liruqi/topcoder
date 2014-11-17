#include<stdio.h>
#include<math.h>

typedef long long ll;

ll p,q,r,t;

int got(){
	ll _m = t*(t-1);
	ll b=_m*p/q;
	if(b*q != _m*p)
		return 0;
	ll x=(sqrt(1.0+4*b)+1+.5);
	x/=2;
	if(x*(x-1) == b){
		r=x;
		if((x-1)*(x-2) == b)
			r=x-1;
		return 1;
	}
	return 0;
}

int main(){
	while(1){
		scanf("%I64u",&p);
		scanf("%I64u",&q);
		if(p==0 && q==0) break;
		for(t=2;t<50001;t++)
			if(got())
			{
				printf("%I64d %I64d\n",r,t-r);
				break;
			}
		if(t==50001)
			puts("impossible");
	}
}
