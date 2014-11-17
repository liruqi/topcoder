#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    const double e = 2.7182818284590452354, pi = 3.141592653589793239;
	int n, arr;
	double a;

	cin>>n;
	
	for (int i=0;i<=n-1;++i)
	{
		cin>>a;
		if(a==1)
			arr=1;
		else
		arr=.5*log10(2*a*pi)+a*log10(a/e)+1;	
cout<<arr<<endl;
		
	}	
	return 0;
}