#include <iostream>
using namespace std;

int t[4]={25,10,5,1};
int c[4];
int N,i,j,tot;
int main()
{
	cin>>N;
	for(i=1;i<=N;i++)
	{
		cin>>tot;
		for(j=0;j<4;j++)
		{
			c[j]=tot/t[j];
			tot-=c[j]*t[j];
		}
		cout<<i<<" ";

        cout<<c[0]<<" QUARTER(S), ";
        cout<<c[1]<<" DIME(S), ";
        cout<<c[2]<<" NICKEL(S), ";
        cout<<c[3]<<" PENNY(S)"<<endl;
		for(j=0;j<4;j++)	c[j]=0;
	}
	return 0;
}