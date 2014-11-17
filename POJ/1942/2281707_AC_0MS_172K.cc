#include <iostream>
using namespace std;

long long C(unsigned int s, unsigned int n){
	unsigned int i;
	long long r=1;
	for(i=1; i<=n; i++){
		r*=s--;
		r/=i;
	}
	return r;
}

int main()
{
unsigned int m, n, s, r;
while(cin>>m>>n && (m+n)){
	s=m+n;
	if(m<n) n=m;
	cout<<C(s, n)<<endl;
}
return 0;
}