#include <iostream.h>

long int l,s,e;
int m;
int main()
{
	while(cin>>l>>m && l && m)
	{
		l++;
		while(m--)
		{	cin>>s>>e;
			l-=(e-s+1);
		}
		cout<<l<<endl;
	}
	return 0;
}