#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vit;
int n;
bool equal(vit &c){
	int e=c[0];
	for(int i=1;i<n;i++)
		if(c[i]!=e)
			return false;
	return true;
}
void pass(vit &c){
	int i;
	for(i=0;i<n;i++)
		c[i]/=2;
	vit p(c);
	rotate(p.begin(), ++p.begin(), p.end());
	for(i=0;i<n;i++)
		c[i]+=p[i];
	for(i=0;i<n;i++)
		c[i]=((c[i]+1)/2)*2;
}

int main(){
	while(cin>>n && n){
		vit cc(n);
		for(int i=0;i<n;i++)
			cin>>cc[i];
		int cnt=0;
		while(!equal(cc)) pass(cc),cnt++;
		cout<<cnt<<" "<<cc[0]<<endl;
	}
}
