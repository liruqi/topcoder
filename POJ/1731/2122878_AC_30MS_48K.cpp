#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char str[205];
main(){ int l;
	gets(str);l=strlen(str);sort(str, str+l);puts(str);
	while(next_permutation(str, str+l)) puts(str);
}
