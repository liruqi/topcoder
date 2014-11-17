#include <iostream>
using namespace std;
long long a,b,N;
void next(int &n)
{
 	long long x=n;
	n = (a*(x*x%N) + b) % N;
}

int main()
{
 	while(cin>>N>>a>>b && N)
	{
	    int t1=0;
	    int t2=0;
		next(t2);
		while(t1!=t2)
		{
			next(t1);
			next(t2);
			next(t2);
		}
		int cnt=1;
		next(t2);
		while(t1!=t2)
		{
		 	next(t2);
		 	cnt++;
	    }
		cout<< N - cnt <<endl;
	}
	return 0;
}