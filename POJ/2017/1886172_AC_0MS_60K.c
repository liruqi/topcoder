#include<stdio.h>
int main ()
{
    int n,a[20],b[20],i,sum,j;
	a[0]=b[0]=0;
	while(scanf("%d",&n) && n>0)
	{	
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i],&b[i]);
		sum=0;
		for(i=1;i<=n;i++)
			sum+=a[i]*(b[i]-b[i-1]);
		printf("%d miles\n",sum);
	}
	return 0;
}
