#include <iostream>
#include <string>
using namespace std;

string s, t;
bool sub()
{
	int i, j;
	for(i=0, j=0; i<s.length() && j<t.length(); )
	{
		while(j<t.length() && t[j]!=s[i])
			j++;
		if(t[j]==s[i]){
			i++;
			j++;
		}
	}
	return ( i==s.length() );
}

int main()
{
	while(cin>>s>>t){
		if(sub())
			puts("Yes");
		else 
			puts("No");
	}
	return 0;
}
