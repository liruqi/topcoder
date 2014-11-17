#include <iostream.h>

char s1[]={"advertise"};
char s2[]={"does not matter"};
char s3[]={"do not advertise"};
int n,i,j,k;
void main()
{
	cin>>n;
	while(n--)
	{
		cin>>i>>j>>k;
		if(i<j-k)
			cout<<s1<<endl;
		else if(i>j-k)
			cout<<s3<<endl;
		else cout<<s2<<endl;
	}
}

