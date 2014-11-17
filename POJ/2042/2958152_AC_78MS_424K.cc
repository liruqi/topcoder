#include <iostream>
 

using namespace std;
const int maxn = 1<<15;

int fsq[maxn];


int main(){

	int n,s1,s2,s3,s4;
	for(int i=1;s1=i*i,s1<maxn;i++){
		for(int j=0;s2=j*j+s1, j<=i&&s2<=maxn;j++)
			for(int k=0;s3=k*k+s2, k<=j&&s3<maxn;k++)
				for(int l=0;s4=l*l+s3, l<=k&&s4<maxn;l++)
					fsq[s4]++;
	}
	while(cin>>n&&n){
		cout<<fsq[n]<<endl;
	}
	return 0;

}
