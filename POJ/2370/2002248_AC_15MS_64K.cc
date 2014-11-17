#include <stdio.h>
#include <algorithm>
using namespace std;

int A[105];
int main()
{
 	int r,i,K;
 	scanf("%d",&K);
 	for(i=0; i<K; i++) scanf("%d",A+i);
 	sort(A,A+K);
	r=K/2+1;
 	for(i=0; i<=K/2; i++) r+=A[i]/2;
 	printf("%d",r);
 	return 0;
}
