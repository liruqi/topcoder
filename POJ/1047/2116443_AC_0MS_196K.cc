#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool verify(string S, int n)
{
	string str=S;
	int i,t,carry=0;
	for(i=S.length()-1; i>=0; i--)
	{
		t=(S[i]-'0') * n;
		t+=carry;
		carry=t/10;
		str[i]=t%10 + '0';
	}
	sort(&S[0], &S[S.size()]);
	sort(&str[0], &str[str.size()]);

	return (!carry) && (S==str);
}

int main()
{
	string S;
	int i;
	while(cin>>S)
	{	
		cout<<S<<" is ";
		for(i=1; i<=S.length(); i++)
		{
			if( !verify(S, i) )
				break;
		}
		if(i==S.length() + 1)
			cout<<"cyclic\n";
		else 
			cout<<"not cyclic\n";
	}
	return 0;
}
