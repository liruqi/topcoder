#include <iostream.h>
int m, n, tc, sum;
int main()
{
	cin>>n;
	while(cin>>tc>>sum)
	{
		int cnt=0, d;
		for(d=1; d*d<=2*sum; d++)
		{
			n=(sum-(d*(d+1))/2)/(d+1);
			m=(sum+(d*(d+1))/2)/(d+1);
			if(n && ((m+n)*(m-n+1)==2*sum)) 
				cnt++;
		}
		cout<<tc<<' '<<cnt<<endl;
	}
	return 0;
}
