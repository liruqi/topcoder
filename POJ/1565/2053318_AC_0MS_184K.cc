#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	long long i,j,sum;
	char str[50];
	cin>>str;
	while(str[0]!='0'){
		sum=0;
		for(i=strlen(str)-1, j=0; i>=0; i--,j++){
			sum+=((2<<j) - 1)*(str[i]-'0');
		}
		cout<<sum<<endl;
		cin>>str;
	}
	return 0;
}
