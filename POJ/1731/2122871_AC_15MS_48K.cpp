#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char str[205];
main(){
	gets(str);sort(str, str+strlen(str));puts(str);
	while(next_permutation(str, str + strlen(str)))	puts(str);
}
