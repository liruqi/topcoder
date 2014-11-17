#include <iostream>
using namespace std;
char ds[2000];
int i,sum;

int main()
{
 	cin>>ds;
	while(ds[0]!='0')
	{
        sum = 0;
 	 	for(i=0; ds[i]!='\0'; i++)
 	 		sum += ds[i] - '0';
		while(sum > 9)
			sum = sum/10 + sum%10;	 
		cout<<sum<<endl;
 	 	cin>>ds;
	}
	return 0;
}
