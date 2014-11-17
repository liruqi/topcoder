#include <stdio.h>
#include <math.h>
#include <algorithm>
#define pi 2 * asin(1)
//１３５８７６４
using namespace std;

int main()
{
    double x1, yy1, r1, x2, yy2, r2;
    double alpha1, alpha2,d,area=0.0,xian;
    scanf("%lf%lf%lf%lf%lf%lf",&x1, &yy1, &r1, &x2, &yy2, &r2);
    d=sqrt((x1-x2)*(x1-x2) + (yy1-yy2)*(yy1-yy2));
    if(r1<r2)
        swap(r1, r2);
    if(r1+r2 <= d)
    {
        printf("%.3f",area);
        return 0;
    }
    if(r1-r2 >=d)
    {
        area = pi * r2 * r2;
        printf("%.3f",area);
        return 0;
    }
    
    alpha1=(d*d + r1*r1 - r2*r2)/(2*d*r1);
    alpha2=(d*d - r1*r1 + r2*r2)/(2*d*r2);
    alpha1=acos(alpha1);
    alpha2=acos(alpha2);
    area=r1*r1*alpha1 + r2*r2*alpha2;
    xian=r1 * sin(alpha1);
    area-=(xian * d);
    printf("%.3f",area);
    while(getchar()!=EOF);
    return 0;
}
