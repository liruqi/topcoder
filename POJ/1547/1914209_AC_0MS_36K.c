#include <stdio.h>
int main()
{
	int t,i,a,b,c,tmp;
	char n[10][20];
	while(scanf("%d",&t) && t>0)
	{
		int max = 0, min = 1000000000;
		int maxi, mini;
		for(i=1;i<=t;i++)
		{
			scanf("%d%d%d%s",&a,&b,&c,n[i]);
			tmp=a*b*c;
			if(tmp > max)
			{
				max = tmp;
				maxi = i;
			}
			if(tmp < min)
			{
				min = tmp;
				mini = i;
			}
		}
		printf("%s took clay from %s.\n",n[maxi],n[mini]);
	}
	return 0;
}
