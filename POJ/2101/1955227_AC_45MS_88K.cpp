#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n,e;
	int a=0,b=0,i,j;
	double res;
	cin>>n>>e;
	for(i=1; i<n; i++)
	{cin>>j; a+=j;}
	for(i=1; i<e; i++)
	{cin>>j; b+=j;}
	a *= a; b *= b; 
	res = sqrt(a+b);
	n = (int)res;
	e = (res - n)>0 ? n+1 : n;
	cout<<e;
	return 0; 
}
