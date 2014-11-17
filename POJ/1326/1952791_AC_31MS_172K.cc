#include <iostream>
#include <string.h>

using namespace std;
char str[80];
int main()
{
	int ans=0;

	cin>>str;
	while(strcmp(str,"#"))
	{
		ans=0;
		while(strcmp(str,"0"))
		{
			int n;
			cin>>str>>n>>str;
			switch(str[0])
			{
			case 'F':
				ans += 2*n;
				break;
			case 'B':
				ans += n;
				n++;
				ans += n/2;
				break;
			case 'Y':
				if(n<500) n = 500;
				ans += n;
				break;
			}
			cin>>str;
		}
		cout<<ans<<endl;
		cin>>str;
	}
	return 0;
}

