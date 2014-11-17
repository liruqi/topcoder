#include <stdio.h>
#define MS 10001
int m[MS],N,i;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",m+i);
	qsort(m,N,4,cmp);
	printf("%d",m[N/2]);
}
