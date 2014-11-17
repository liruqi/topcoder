#include <iostream>
using namespace std;


void main()
{
	int n,k,sum,x;
	cin>>n;
	while(n--)
	{
		cin>>k;
		sum=1-k;
		while(k--)
		{
			cin>>x;
			sum+=x;
		}
		cout<<sum<<endl;
	}
}
