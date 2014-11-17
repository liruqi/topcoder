#include <iostream.h>
#include <string.h>

#define MS 100001
char s[MS],t[MS];
int sl,tl,i,j;
int main()
{
	while(cin>>s>>t)
	{
		sl=strlen(s);tl=strlen(t);

		for(i=0,j=0; (j<tl) && (i<sl); j++)
		{
			if(s[i]==t[j])
				i++;
		}
		if(i==sl) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
