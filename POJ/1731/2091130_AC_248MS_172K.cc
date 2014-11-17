#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

char str[205];	
int cmp(const void *a, const void *b)
{
 	int m=*(char *)a;
 	int n=*(char *)b;
 	return m-n;
}
int main(){	
	int len;
	cin>>str;
	len=strlen(str);
	qsort(str, len, 1, cmp);
	cout<<str<<endl;
	while(next_permutation(str, str + len))
	{
	 	cout<<str<<endl;
	}
	
	//system("pause");
	return 0;
}
