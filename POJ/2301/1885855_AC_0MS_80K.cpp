#include <iostream.h>
int main()
{
	int N,s,d;
	cin>>N;
	while(N--)
	{	
		cin>>s>>d;
		if(s<d || (s+d)%2)
			cout<<"impossible"<<endl;
		else
		{
			cout<<(s+d)/2<<" "<<(s-d)/2<<endl;	
		}
	}
	return 0;
}