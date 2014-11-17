#include<iostream.h>
long jc(long a,long n);
int main()
{
	long b,n;
	cin>>b>>n;
	while(b!=0&&n!=0)
	{
		for(long a=0;a<=b;a++)
		{
			if(jc(a,n)>=b)
			{
				if((b-jc(a-1,n))>(jc(a,n)-b))
					cout<<a<<endl;
				else
					cout<<a-1<<endl;
				break;
			}
		}
		cin>>b>>n;
	}
	return 0;
}

long jc(long a,long n)
{
	long sum=1;
	for(long i=0;i<n;i++)
	{
		sum=sum*a;
	}
	return sum;
}
