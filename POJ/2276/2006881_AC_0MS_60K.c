#include <stdio.h>
#include <math.h>
#define pi 3.1415972658

int main()
{
 	double D,H,height;
 	double a1,a2,a3;
 	scanf("%lf%lf",&D,&H);
 	while(scanf("%lf%lf%lf",&a1,&a2,&a3) && a1){
		a1*=(pi/180.0);
		a2*=(pi/180.0);
		a3*=(pi/180.0);

		a1=tan(pi/2.0 - a1);
		a2=tan(pi/2.0 - a2);
		a3=tan(pi/2.0 - a3);
		
		height = D*sqrt( 2.0/(a1*a1+a3*a3-2*a2*a2) );
		height+=H;
		printf("%.0f\n",height);
	}
	return 0;
}
