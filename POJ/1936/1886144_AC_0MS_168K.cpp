#include <iostream.h>
#include <string.h>

#define MS 100001
char s[MS],t[MS];
int i,j;
int main()
{
	while(cin>>s>>t)
	{
		for(i=0,j=0; (s[i]!='\0') && (t[j]!='\0'); j++)
		{
			if(s[i]==t[j]) i++;
		}
		if(s[i]=='\0') cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
