#include <stdio.h>
#include <algorithm>
using namespace std;
char str[52];
int main()
{
    while(scanf("%s", str)!=EOF)
    {
    if(str[0]=='#') break;
    if( next_permutation(str, str + strlen(str)) )
        puts(str);
    else
        puts("No Successor");
    }

    return 0;
}
