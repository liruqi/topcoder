#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxn 50001
int A[maxn];

int heapIns(int p){
	int c=p;A[p]=p+1;
	while(c>1){
		swap(A[c],A[c/2]);
		c/=2;
	}
}

int main(){
	int i,n;
	while(~scanf("%d",&n)){
	for(i=1;i<n;i++)heapIns(i);A[n]=1;
	for(i=1;i<=n;i++)printf("%d%c",A[i],i==n?'\n':' ');
	}
}