#include <iostream>
//#include <stdio.h>
#include <cmath>
using namespace std;

int m, n, tc, up, sum;
bool ok()
{
	return n && m>n && ((m+n)*(m-n+1)==2*sum);
}


int main()
{
	cin>>n;
	while(cin>>tc>>sum)
	{
		int cnt=0, up=sqrt(2*sum), d;
		for(d=0; d<=up; d++)
		{
		//	n=(2*sum-d*d-d)/(2*(d+1));
		//	m=(2*sum+d*d+d)/(2*(d+1));
			n=(sum-(d*(d+1))/2)/(d+1);
			m=(sum+(d*(d+1))/2)/(d+1);
			if(ok()) {
				cnt++;
		//		cout<<m<<' '<<n<<endl;
			}
		}
		cout<<tc<<' '<<cnt<<endl;
	}
	return 0;
}
