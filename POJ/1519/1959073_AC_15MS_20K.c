#include <stdio.h>
int main()
{
 	char c;
	int sum;
	while( (c = getchar()) != '0')
	{
	    sum = c - '0';
        while( (c=getchar()) != 10 )
            sum += c - '0';
		while(sum > 9)
			sum = sum/10 + sum%10;
		printf("%d\n",sum);
	}
	return 0;
}