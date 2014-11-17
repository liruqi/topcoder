#include <iostream>
using namespace std;

int h[50];
int main()
{
	int m,n,i,t=0,sum=0;
	while(cin>>n && n>0)
	{
        ++t;
		cout<<"Set #"
			<<t
			<<endl;
		for(sum=0,i=0;i<n;i++)
		{
			cin>>h[i];
			sum+=h[i];
		}
		sum /= n;
		for(m=0,i=0;i<n;i++)
		{
			if(h[i]>sum)
			{
				m+=(h[i]-sum);	
			}
		}
		cout<<"The minimum number of moves is "
			<<m
			<<"."
			<<endl<<endl;
	}
	return 0;
}
