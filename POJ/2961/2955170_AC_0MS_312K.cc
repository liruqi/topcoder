#include <iostream>

using namespace std;

typedef long long llg;

int f(llg i,llg j,llg n){
	if(n<=1)return 1;
	llg k=n/2;
	if(i<k){
		if(j<k)return f(i,j,k);
		else return f(i,j-k,k);
	}
	else {
		if(j<k)return f(i-k,j,k);
		else return -f(i-k,j-k,k);
	}
}


int main(){

	llg ks,n,x,y,w,h;
	cin>>ks;
	while(ks--){
		cin>>n>>x>>y>>w>>h;
		for(llg i=y;i<y+h;i++)
			for(llg j=x;j<x+w;j++){
				cout<<f(i,j,n);
				cout<<(j+1==x+w?'\n':' ');
			}
		cout<<endl;
	}
	return 0;

}
