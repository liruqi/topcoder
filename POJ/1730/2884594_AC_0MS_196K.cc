#include<stdio.h>
#include<math.h>
#define zero 1e-6
typedef long long l64;
int powb(l64 t,l64 x)
{
	if(2==t%4)
		return 1;
	int b=2,p=1,a=1;
	if(t%5==2||t%5==3||x<0)
		a=2;
	for(int i=a+1;b>1;i+=a)
	{
		b = (int)(pow(t,1.0/i)+zero);
		if(fabs(pow(b,i)-t)<zero)
			p = i;
	}
	return p;
}

int main()
{
	l64 x;
	while(scanf("%I64d",&x) && x)
		printf("%d\n",powb(x>0?x:-x,x));
	return 0;
}