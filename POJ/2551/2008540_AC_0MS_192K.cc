#include<iostream>
using namespace std;

int main()
{
	unsigned n, a, total;
	while(cin>>n)
	{
		a = total = 1;
		while(a)
		{
			a = a * 10 + 1;
			total++;
			a %= n;
		}
		cout<<total<<endl;
	}
	return 0;
}
