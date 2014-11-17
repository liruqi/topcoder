#include<stdio.h>

int main()
{
	int k;
	double p;
	while(scanf("%d", &k) != -1 && k)
	{
		scanf("%lf", &p);
		printf("%.3lf %.3lf\n", k/p, k*(k+1-p)/p/p);
	}
}
