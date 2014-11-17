#include <stdio.h>
#include<math.h>
void main()
{
    double n,m;
    while(scanf("%lf%lf",&n,&m)!=EOF) 
		printf("%.0lf\n",pow(m,1/n));
}
