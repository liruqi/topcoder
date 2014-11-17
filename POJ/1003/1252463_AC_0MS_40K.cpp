#include<stdio.h>
void main()
{
	float a,result=0;
	int n = 2;
	scanf("%f",&a);
	while(a!=0)
	{
		for (n=2,result=0; result<a; n++)
		{
			result += (float)1 / n;
		}	
		printf("%d card(s)\n",n-2);
		scanf("%f",&a);
	}
}

