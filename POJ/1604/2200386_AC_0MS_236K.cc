#include <stdio.h>

int A[10001];

int del5(int n){
	int m=n/5;
	if(n==m*5)
		return del5(m);
	return n;
}

int noz(int n){
	int r=n/5; n=r;
	while(n){
		r+=n/5;
		n/=5;
	}
	return r;
}

int del2(int n, int c){
	if(c>0){
		n/=2;
		return (n%2) ? del2(n+5, c-1):del2(n, c-1);
	}
	return n;
}

int main()
{
	int n,i;
	A[1]=1;
	for(i=2; i<=10000; i++){
		A[i]=( A[i-1] * del5(i) )%10;
	}
	while( scanf("%d",&n)!=EOF ){
		int nt = noz(n);
		printf("%5d -> %d\n", n, del2(A[n], nt));
	}
	return 0;
}
