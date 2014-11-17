//2183
#include <iostream>
#define maxn 1000000
using namespace std;
char vst[maxn];
int next(int n){
	n/=10; n%=10000; n*=n;
	return n%1000000;
}
int main(){
	int n,m,md,ll;
	cin>>n;
	for(m=n, md=0;!vst[m];m=next(m), md++)
		vst[m]=1;
	int frt=m;
	for(m=n, ll=0;m!=frt;m=next(m), ll++);
	ll = md - ll;
	cout<<frt<<" "<<ll<<" "<<md<<endl;
}
