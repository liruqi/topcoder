#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int mx = 110;

int n,i,r;
int A[mx],B[mx];
int mid(int a,int b,int c){
return a+b+c - max(max(a,b),c) - min(min(a,b),c);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",A+i);
	B[1]=A[1];B[n]=A[n];
	for(i=2;i<n;i++)B[i]=mid(B[i-1],A[i],A[i+1]);
	for(i=2;i<=n;i++)
		r+=(abs(A[i]-B[i])+abs(B[i]-B[i-1]));
	printf("%d\n",r);
}

