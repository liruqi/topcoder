#include <stdio.h>

int n,i;
double a[3010],c[3010],d,fn;;
int main()
{
	scanf("%d",&n);
	scanf("%lf %lf",a,(a+n+1));
	for(d=0.0,i=1;i<=n;i++)
	{
		scanf("%lf",&c[i]);
		d+=(n+1-i)*c[i];
	}
	fn=(double)n;
	d=(a[n+1] + a[0]*fn - 2.0*d)/(double)(n+1);
	printf("%.2f\n",d);

	return 0;
}