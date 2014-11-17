#include <iostream>
using namespace std;

int main()
{
	int i, a, b, A, B;
	while(cin>>a>>b ){
		if(a==0 && b==0) 
			return 0;
		int cnt=0, carry=0;
		while(a || b || carry){
			A=a%10;
			B=b%10;
			a/=10;
			b/=10;
			if(A+B+carry >= 10)
			{
				carry=1;
				cnt++;
			}
			else
				carry=0;
		}
		if(cnt) 
			cout<<cnt
				<<( (cnt==1)?" carry operation.":" carry operations." )
				<<endl;
		else
			cout<<"No carry operation."<<endl;
	}
}
