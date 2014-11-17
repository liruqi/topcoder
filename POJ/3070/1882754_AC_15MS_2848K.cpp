#include <iostream>
#define MS 10000001
using namespace std;

int t[10]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
int bt[MS];
int F(int n)
{
	if(n<9)
		return t[n];
	else
	{
		int a=n/2;
		int b=n-a;
		if(n<MS)
		{
			if(!bt[n])
			{
				bt[n]=(F(a+1)*F(b)+F(a)*F(b-1))%10000;	
			}
			return bt[n];
		}
		else
			return (F(a+1)*F(b)+F(a)*F(b-1))%10000;
	}
}

int n;
int main()
{
	while(cin>>n && n>=0) cout<<F(n)<<endl;
	return 0;
}