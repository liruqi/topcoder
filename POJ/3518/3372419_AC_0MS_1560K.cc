#include<stdio.h>
#include<string.h>

#define mx 1299709+1
bool prm[mx];
typedef unsigned int uint;
uint k,m;


void init(){
	memset(prm,1,sizeof(prm));
	int i,j;
	for(i=2;(j=i*i)<mx;i++) if(prm[i]){
		for(;j<mx;j+=i) prm[j]=0;
		//printf("%d\t",i);
	}
}


uint n;
uint slv(){
	if(prm[n]) return 0;
	int len=0,i;
	for(i=n;!prm[i];i++)len++;
	for(i=n;!prm[i];i--)len++;
	return len;
}

int main(){
	init();
	while(1){
		scanf("%u",&n);
		if(n==0) break;
		printf("%u\n",slv());
	}
}
