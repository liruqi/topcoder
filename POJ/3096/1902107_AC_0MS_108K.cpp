#include <iostream>
#define MAX 81
using namespace std;
char str[MAX];

bool s_judge()
{
	int i,j,n;
	if(str[1] == '\0') return true;
	for(n=0; str[n+2] != '\0';)
	{
		n++;
		for(i=0; str[i+n]!='\0'; i++)
		{
			for(j=i+1; str[j+n]!='\0'; j++)
				if(str[i]==str[j] && str[i+n]==str[j+n]) 
					return false;
		}
	}
	return true;
}

int main()
{
	while(cin>>str && str[0] != '*')
	{
		cout<<str
				<<" is";
		if( !s_judge() )
		{
			cout<<" NOT";
		}
		cout<<" surprising."<<endl;
	}
	return 0;
}