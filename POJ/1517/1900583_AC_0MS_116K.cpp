#include <iostream>
#include <iomanip>
using namespace std;
int i,j,n;
double ans;
int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	for(n=0;n<10;n++)
	{
		cout<<n<<" ";
		for(ans=1,i=1;i<=n;i++)
			ans+=1.0/fac[i];
		cout<<setprecision(10)
            <<ans
            <<endl;
	}
	return 0;
}
