#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char str[205];
int main(){
	int len;
	cin>>str;
	len=strlen(str);
	sort(str, str+len);
	cout<<str<<endl;
	while(next_permutation(str, str + len))
	 	cout<<str<<endl;
	
	return 0;
}
