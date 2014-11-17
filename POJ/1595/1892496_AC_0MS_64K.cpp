#include <stdio.h>
#include <string.h>
#define MS 1010
bool prime[MS];
int t[MS/2];
int main()
{
	int i, j;
	memset(prime, true, sizeof(prime));
	prime[0]=false;
	for(i = 2; i <= MS/2; i++)
	{
		if(prime[i])
		{
			for(j = 2; j * i< MS; j++)
			{
				prime[j * i] = false;
			}
		}
	}
	int n,m;
	
	while(scanf("%d%d",&n,&m) != EOF)
	{
		printf("%d %d:",n,m);
		for(i=1,*t=0;i<=n;i++)				//1 is not a prime
			if(prime[i])
			{
				t[0]++;
				t[*t]=i;
			}
		if(t[0]%2)						//odd number 
		{
			i=1-m+(t[0]+1)/2;
			j=m-1+(t[0]+1)/2;
		}
		else
		{
			i=1-m+t[0]/2;
			j=m+t[0]/2;
		}
		if(i>0)
		{
			for(;i<=j;i++) printf(" %d",t[i]);
		}
		else
		{
			for(i=1;i<=t[0];i++) printf(" %d",t[i]);
		}
		printf("\n\n");
	}
	return 0;
}