#include <iostream>
using namespace std;


int C(int n)
{
 	int cnt=0;
 	for(; n>1 ; n/=2)
 	{
	 	cnt+=n/2;
    }
    return cnt;
}

int main()
{
 	int n, k;
 	while(cin>>n>>k)
 	{
	 	cout<<( C(n)-C(n-k)-C(k)>0  ? 0 : 1)<<endl;
	}
	return 0;
}
