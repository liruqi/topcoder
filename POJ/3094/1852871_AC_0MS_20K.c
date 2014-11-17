#include <stdio.h>

void main()
{
	char c;
	int qs=0,n=0;
	while((c=getchar())!='#')
	{
		if(c == ' ')
		{
			n++;
			continue;
		}
		if(c != 10)
		{
			n++;
			qs += n*(int)(c - '@'); 
		}
		else
		{
			printf("%d\n",qs);
			qs=0; 
			n=0;
		}
	}
}