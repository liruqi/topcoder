#include<stdio.h>
int f(int a, int b){ 
	return (a == 0) ? b : f(b % a, a);
}
main()
{
	int b[1006],temp=1,x,y,te,s=1;
	int n,i,t,a[1006],c[1006],j=1;
	scanf("%d",&n);
	for(i=0;i<1004;i++)
	   c[i]=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);		
	for(i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			t=a[i];c[i]=1;
		    while(i!=t)
			{c[t]=1;t=a[t];s=s+1;}
			b[j]=s;j++;s=1;
		}
	}
	for(i=2;i<j;i++)
	{
		x=b[i-1];y=b[i];te=x*y;
		temp=f(x,y);
		if(temp>0)
		  b[i]=te/temp;
	}
	printf("%ld",b[i-1]);
}