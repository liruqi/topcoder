#include<stdio.h>

typedef unsigned int uint;
uint k,m;

uint slv(uint n){
	if(n==1)return 0;
	return (k+slv(n-1))%n;
}

int main(){
	uint n;
	while(1){
		scanf("%u",&n);
		scanf("%u",&k);
		scanf("%u",&m);
		if(n==0) break;
		printf("%u\n",(slv(n-1)+m)%n+1);
	}
}
