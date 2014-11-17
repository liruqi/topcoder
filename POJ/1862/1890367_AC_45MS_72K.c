#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}
int s[100],i,n;
double ans;
int main()
{
	scanf("%d",&n);
	for(i=0; i<n ;i++)
	{
		scanf("%d",&s[i]);
	}
	if(n==1)	
	{
		ans= (double)s[n-1];
		printf("%.3f",ans);
		return 0;
	}
	qsort(s,n,4,cmp);
	ans=2 * sqrt( (double)(s[n-1]*s[n-2]) );
	for(i=n-3;i>=0;i--)
		ans = 2.0 * sqrt(ans*(double)s[i]);
    printf("%.3f",ans);
	return 0;
}
