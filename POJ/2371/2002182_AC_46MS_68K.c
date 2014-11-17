#include <stdio.h>
#define MaxN 5010
int A[MaxN];
int main()
{
 	int n,i,t,K;
 	scanf("%d",&n);
 	while(n--){
		scanf("%d",&i);
		A[i]++;
	}
	scanf("%*s%d",&n);
 	while(n--){
 		scanf("%d",&K);
 		for(i=1,t=0;t+A[i]<K;i++)
 			t+=A[i];
		printf("%d\n",i);
	}
	return 0;
}
