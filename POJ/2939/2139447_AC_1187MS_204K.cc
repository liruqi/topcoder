#include <iostream>
using namespace std;
long long a,b,N;
int next(int n)
{
 	long long x=n;
	return (a*(x*x%N) + b) % N;
}

int main()
{ 	
 	while(cin>>N>>a>>b && N)
	{
	    int t1=0;
	    int t2=next(0);
		while(t1!=t2)
		{
			t1=next(t1);
			t2=next(t2);
			t2=next(t2);
		}
		int cnt=1;
		t2=next(t1);
		while(t1!=t2)
		{
		 	t2=next(t2);
		 	cnt++;
	    }
		cout<< N - cnt <<endl;
	}
	return 0;
}

/*
#include <map>
using namespace std;

long long a,b,N,x;
int main()
{	
	int cnt, n;
	while(cin>>N>>a>>b && N)
	{
	    map<int, int>M;
        cnt=1;
        n=0;
		while(M[n]==0)
		{
			M[n]=cnt++;
			x=n;
			n=(a*(x*x%N) + b) % N;
		}
		cout<<N-(cnt-M[n])<<endl;
	}
	return 0;
}
*/
