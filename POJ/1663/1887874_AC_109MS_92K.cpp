#include <iostream>
using namespace std;
int i,N,x,y;
int main()
{
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>x>>y;
		if(x==y)
		{
			if(x%2)	//x is odd
			{
				x=x*2-1;
			}
			else
				x *= 2;
			cout<<x<<endl;
		}
		else if(x==y+2)
		{
			if(y%2)
				y=2*y+1;
			else
				y=2*(y+1);
			cout<<y<<endl;
		}
		else
			cout<<"No Number"<<endl;
	}
	return 0;
}