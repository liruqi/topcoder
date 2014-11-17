#include<stdio.h>

__int64 ExtendedGcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
	__int64 d,px,py;
	if(!b)
	{
		x=1,y=0;
		return a;	
	}		
	d=ExtendedGcd(b,a%b,px,py);

	x=py;
	y=px-(a/b)*py;
	return d;
}

int main()
{
	__int64 a,b,c,k,d,x,y;
	while(scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&k)!=EOF&&(a||b||c||k))
	{
			
			k=1<<k;
			d=ExtendedGcd(c,k,x,y);
			
			if((b-a)%d) printf("FOREVER\n");
			else printf("%I64d\n",((x*(b-a)/d)%(k/d)+(k/d))%(k/d));
	}	
	return 0;
} 