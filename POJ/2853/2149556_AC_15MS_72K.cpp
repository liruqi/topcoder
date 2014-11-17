#include <iostream.h>
#include <math.h>
int m, n, tc, up, sum;
main()
{
	cin>>n;
	while(cin>>tc>>sum)
	{
		int cnt=0, up=sqrt(2*sum), d;
		for(d=0; d<=up; d++)
		{
			n=(sum-(d*(d+1))/2)/(d+1);
			m=(sum+(d*(d+1))/2)/(d+1);
			if(n && m>n && ((m+n)*(m-n+1)==2*sum)) 
				cnt++;
		}
		cout<<tc<<' '<<cnt<<endl;
	}
}
