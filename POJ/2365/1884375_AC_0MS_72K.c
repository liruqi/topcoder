#include<stdio.h>
#include<math.h>
#define pi 2.0*asin(1.0)
int main()
{
    double x,y,xo,yo,a,b,r,l=0.0;
	int n,i;
	scanf("%d%lf",&n,&r);
	scanf("%lf%lf",&xo,&yo);
    x=(a=xo); y=(b=yo);		//record starting point
    for(i=1;i<n;i++)
	{
        scanf("%lf%lf",&xo,&yo);
        l+=sqrt((xo-x)*(xo-x)+(yo-y)*(yo-y));
        x=xo;
        y=yo;
    }
    l+=sqrt((xo-a)*(xo-a)+(yo-b)*(yo-b));
    l+=2.0*pi*r;
    printf("%.2lf\n",l);
    return 0;
}
