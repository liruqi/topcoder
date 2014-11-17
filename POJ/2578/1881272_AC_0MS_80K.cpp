#include <iostream.h>
int main()
{
	int i,j;
	bool f=1;
	for(i=0;i<3;i++)
	{	
		cin>>j;
		if(j<=168 && f)
		{
			cout<<"CRASH "<<j<<endl;
			f=0;
		}
	}
	if(f) cout<<"NO CRASH"<<endl;
	return 0;
}