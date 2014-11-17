#include <iostream>
using namespace std;

bool n[100];
int main()
{
	int	i=1,j=1;
	int in;
	while(cin>>in && in>0)
	{
		for(i=0;i<100;i++)
			n[i]=0;
		int c=0;
		n[in]=1;

		while(cin>>i && i)
			n[i]=1;

		for(i=0;i<100;i++)
			if(n[i] && 2*i<100)
				if(n[2*i])
					c++;
		cout<<c<<endl;
	}
	return 0;
}