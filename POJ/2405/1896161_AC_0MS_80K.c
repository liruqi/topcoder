#include <math.h>
#include <stdio.h>

#define Pi 3.1415926

void main()
{
	double D;
	double d;
	double V;

	while(scanf("%lf%lf",&D,&V),D && V)
	{
		d=pow(D*D*D-6*V/Pi,1.0/3);
		printf("%.3lf\n",d);
	}
}
 
