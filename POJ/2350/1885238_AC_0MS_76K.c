#include <stdio.h>
#include <stdlib.h>
#define MS 1000

int g[MS];
int cmp(const void*a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int t,n,i,s;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(s=i=0;i<n;i++)
		{
			scanf("%d",g+i);
			s+=*(g+i);
		}
		qsort(g,n,4,cmp);
		for(i=0;i<n;i++)
			if(g[i] * n>s)
				break;
		i=n-i;
		ans=(double)(i*100)/n;
		printf("%.3lf%%\n",ans);
	}
	return 0;
}