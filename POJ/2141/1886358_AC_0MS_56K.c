#include <stdio.h>
#include <ctype.h>
#include <string.h>

char lc[27];
char uc[27],c;
int main()
{	
	int i;
	scanf("%s",lc);
	for(i=0;i<26;i++)
		uc[i]=toupper(lc[i]);
	uc[i]=lc[i];
	getchar();
	while((c=getchar())!=EOF)
	{
		if(isalpha(c))
		{
			if(isupper(c))
				c=uc[c-'A'];
			else
				c=lc[c-'a'];
		}
		if(c==10)
			break;
		putchar(c);
	}
	return 0;
}