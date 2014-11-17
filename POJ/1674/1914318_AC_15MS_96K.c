#include<stdio.h>
void main()
{
         short n, a[10005], i, cas,  pos[10005];
	scanf("%d",&cas);
	while(cas--)
	{
		int sum = 0;
		scanf("%d",&n);
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]] = i;
		}

		for(i = 1;i <= n;i++)
		{
			if(a[i] != i)
			{
			   a[pos[i]] = a[i];
			   pos[a[i]] = pos[i];	
			   sum++;
			}
		}
		printf("%d\n",sum);
	}
}

