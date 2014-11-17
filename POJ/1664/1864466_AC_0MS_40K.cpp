#include<iostream.h>

int PA(int a,int b,int c)
{
	int s;
	if(b<=1)
		return 1;
	if(b*c>a)
		return 0;
	for(s=0;b*c<=a;c++)
	{	
		s+=PA(a-c,b-1,c);
	}
	return s;
}

int main()
{
	int t,a,b,i,j;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<PA(a,b,0)<<endl;
	}
	return 0;
}