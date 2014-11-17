#include <iostream.h>
int h,s,n;
int t[24] = {12,13,14,15,16,17,18,19,20,21,22,23,24,1,2,3,4,5,6,7,8,9,10,11};

char c;
void main()
{
	cin>>n;
	while(n--)
	{
		cin>>h>>c>>s;
		if(s)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<t[h]<<endl;
	}
}