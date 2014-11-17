#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N, M, cnt=0;
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		int t;
		cin>>t;
		if(pow(t, M) > 0) cnt+=(int)pow(t, M);
	}
	cout<<cnt;
	return 0;
}
