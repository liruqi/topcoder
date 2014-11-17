#include <stdio.h>
void main()
{
	double xinxi[100000],sum=0;
	long i;
	for (i=1;i<100000;i++)
	{
		sum+=1.000000/(2*i);
		xinxi[i]=sum;
	}
	printf("Cards  Overhang\n");
	while (scanf("%ld",&i)!=-1)
		printf("%5d%10.3f\n",i,xinxi[i]);
}
