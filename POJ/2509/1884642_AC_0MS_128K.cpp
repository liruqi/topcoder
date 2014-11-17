#include <iostream>
#define MS 100000
using namespace std;

int cig,cnt,i,k;
int Cal_Cig(int b)
{
	if(b<k)
		return 0;
	else
		{
			int c=b/k;
			return c+Cal_Cig(c+b%k);
		}

}
int main()
{
	while(cin>>cig>>k)
	{
		cnt=cig+Cal_Cig(cig);
		cout<<cnt<<endl;
	}
	return 0;
}
