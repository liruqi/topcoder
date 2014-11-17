#include<stdio.h>
void main()
{
	int n,k;
	__int64 r,i;
	while (scanf("%d%d",&n,&k)==2 && n)
	{
		if(k>n-k)
			k=n-k;
		
		for(r=1,i=1;i<=k;i++)
		{
			r*=n+1-i;
			r/=i;
		}
		printf("%I64d\n",r);
	}
}
