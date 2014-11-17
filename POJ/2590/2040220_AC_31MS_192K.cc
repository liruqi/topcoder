#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	int T,s,e;
	cin>>T;
	while(T--){
		cin>>s>>e; e-=s;
		if(e<0) e=-e;
		s=sqrt(e);
		while(s*(s+1)>e) s--;
		s=s*2+(e-s*(s+1)+s)/(s+1);
		cout<<s<<endl;
	}
	return 0;
}
