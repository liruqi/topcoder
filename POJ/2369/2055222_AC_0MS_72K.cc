#include<stdio.h>
int n,i,t,a[1006],c[1006],j=1;
int gcd(int a, int b){
	int rem;		//remainder
	if(a<b) 
	    return gcd(b,a);
	while(a%b > 0){		//expect a>b
		rem=a%b;
		a=b;
		b=rem;
	}
	return b;
}
main()
{
	int b[1006],x,y,s=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			t=a[i];c[i]=1;
		    while(i!=t)
			{
			 	c[t]=1;t=a[t];s=s+1;
			}
			b[j]=s;j++;s=1;
		}
	}
	for(i=2;i<j;i++)
	{
		x=b[i-1];
		y=b[i];
 		b[i]=x*y/gcd(x,y);
	}
	printf("%d",b[i-1]);
}
