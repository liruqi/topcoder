#include <iostream>
using namespace std;

int i,j,n;
int main()
{
	while(cin>>n && n>0)
	{
		int sum=0,coin=1;
		for(i=1; i <= n; i += coin)
		{
			sum += coin * coin;
			coin++;
		}
		i -= coin;
		sum += coin * (n-i);
		cout<<n
				<<" "
				<<sum
				<<endl; 
	}
}
