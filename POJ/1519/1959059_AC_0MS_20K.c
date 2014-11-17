#include <stdio.h>

char c;
int i,sum;

int main()
{
 	c = getchar();
	while(c != '0')
	{
	    sum = c - '0';
        while( (c=getchar()) != '\n' )
            sum += c - '0';
		while(sum > 9)
			sum = sum/10 + sum%10;
		printf("%d\n",sum);
		
 	 	c = getchar();
	}
	return 0;
}
