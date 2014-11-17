#include <stdio.h>
#define PI 3.1415927

int main()
{
    double d=0.0,t=0.0,dis,vel;
    int rev=0;
    int count=0;
    scanf ("%lf %d %lf",&d,&rev,&t);
    while (rev > 0)
    {
        count++;
        dis = PI*rev*d*(1.0/12)*(1.0/5280);
        vel = dis * 3600.0 / t;
        printf("Trip #%d:",count);
        printf(" %.2f %.2f\n",dis,vel);
		scanf ("%lf %d %lf",&d,&rev,&t);
    }
    return 0;
}

