#include <stdio.h>

int n,i;
double a[2],c,d;
int main()
{
	scanf("%d",&n);
	scanf("%lf %lf",a,(a+1));
	for(d=0.0,i=1;i<=n;i++)
	{
		scanf("%lf",&c);
		d+=(n+1-i)*c;
	}
	d=(a[1] + a[0]*n - 2.0*d)/(double)(n+1);
	printf("%.2f\n",d);

	return 0;
}