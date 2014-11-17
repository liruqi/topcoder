#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main()
{
    int n,i,t;
    double r,R,sinv;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf%d",&R,&n);
        printf("Scenario #%d:\n",i);
        sinv=sin(pi/(double)n);
        r=R / (1.0 + (1/sinv));
        printf("%.3f\n\n",r);
    }
    return 0;
}
