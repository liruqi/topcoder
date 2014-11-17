#include<stdio.h>
int n,i,t,a[1006],c[1006],j=1;
int f(int a, int b){ 
	return (a == 0) ? b : f(b % a, a);
}

main()
{
	int b[1006],temp,x,y,s=1;
	scanf("%d",&n);
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
		x=b[i-1];y=b[i];
		temp=f(x,y);
		if(temp>0)
		  b[i]=x*y/temp;
	}
	printf("%ld",b[i-1]);
}