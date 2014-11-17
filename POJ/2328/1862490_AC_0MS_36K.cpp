#include <iostream.h>
char s1[6],s2[5];

int main()
{
	int h=11,l=0,n;
	bool f=0;
	while(cin>>n && n)
	{
		cin>>s1>>s2;
		switch(s2[0])
		{
		case 'h':
			if(n<h)
				h=n;
			if(n<=l)
				f=1;
			break;
		case 'l':
			if(n>l)
				l=n;
			if(n>=h)
				f=1;
			break;
		case 'o':
			if(n<=l || n>=h)
				f=1;
			if(f)
				cout<<"Stan is dishonest"
					<<endl;
			else
				cout<<"Stan may be honest"
					<<endl;
			f=0;h=11;l=0;
			break;
		}
	}
	return 0;
}