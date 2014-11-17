#include <stdio.h>
int main()
{
	int n,i,ways;
	scanf("%d",&n);
	ways = 0;
	if(n%2)
		ways++;
	for(i = 1;i < n;i = i + 2)
	{
		if(n%i == 0)
			ways++;
	}
	printf("%d\n",ways);
	return 0;
}
