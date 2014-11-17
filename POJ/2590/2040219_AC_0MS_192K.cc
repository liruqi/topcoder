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
		if(s*(s+1)==e) 
		    s*=2;
		else if(e-s*(s+1)<=s+1)
			s=2*s+1;
		else
			s=s*2+(e-s*(s+1)+s)/(s+1);
		cout<<s<<endl;
	}
	return 0;
}
