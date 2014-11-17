#include <stdio.h>
#include <stdlib.h>
int cmp(void const *a,void const *b){
	return *(int *)a - *(int *)b;
}	
int A[105];
int main()
{
 	int r,i,K;
 	scanf("%d",&K);
 	for(i=0; i<K; i++) scanf("%d",A+i);
 	qsort(A,K,4,cmp);
	r=K/2+1;
 	for(i=0; i<=K/2; i++) r+=A[i]/2;
 	printf("%d",r);
 	return 0;
}
