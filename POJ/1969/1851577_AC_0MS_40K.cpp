#include<iostream.h>
#include<math.h>
int cc(int n)	//calculate the colume
{
	int i=0,r=1;
	while(n >= 1 + i*(i+1)/2)
		++i;
	return --i;

}

void  main()
{
	long num,a,b,c,d;
	while(cin>>num)
	{
		c=cc(num);
		d = num - 1 - c*(c+1)/2;
		b=1+d;
		a=1+c-d;
		if(!(c%2))
		{
			c=b;
			b=a;
			a=c;
		}
		cout<<"TERM "<<num<<" IS "<<b<<"/"<<a<<endl;
	}
}
/*
the fifth term is 2/2, and so on.

Input

*/
