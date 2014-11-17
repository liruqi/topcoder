#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double vs,r,c,w,vr,zc;
    int t;
    scanf("%lf%lf%lf%d",&vs, &r, &c, &t);
    while(t--)
    {
    	scanf("%lf",&w);
    	zc = 1.0/(w * c);
    	vr = vs * r/sqrt(zc*zc + r*r);
    	printf("%.3f\n",vr);
    }
      
    return 0;
}
