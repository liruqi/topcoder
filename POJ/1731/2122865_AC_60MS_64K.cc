#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char str[205];
int main(){
	int len;
	gets(str);
	len=strlen(str);
	sort(str, str+len);
	puts(str);
	while(next_permutation(str, str + len))
	 	puts(str);;	
	return 0;
}
