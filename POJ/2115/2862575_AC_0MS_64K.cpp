#include <stdio.h>


__int64 extGcd(__int64 &x,__int64 &y,__int64 a,__int64 b){
	if(b==0) {
		x=1,y=0;
		return a;
	}
	__int64 xx,yy;
	__int64 cd=extGcd(xx,yy,b,a%b);
	x = yy;
	y = xx-(a/b)*yy;
	return cd;
}

__int64 A,B,C,K;
void solve(){
	__int64 x,y,z = B-A;
	if(z==0) {
		puts("0");
		return;
	}
	__int64 cd = extGcd(x,y,C,K);
	if(z%cd){
		puts("FOREVER");
		return;
	}
	__int64 quo=z/cd;
	__int64 add=K/cd;
	x *= quo;
	y *= quo;
	x = x % add + add;
	printf("%I64d\n", x%add);
}

int main(){
	while(~scanf("%I64d%I64d%I64d%I64d",&A,&B,&C,&K)){
		if(A+B+C+K==0) break;
		K = (1<<K);
		solve();
	}
}