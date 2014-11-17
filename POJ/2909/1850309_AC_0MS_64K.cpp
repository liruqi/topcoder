#include <stdio.h>
#include <math.h> /* sqrt(); */

#define UPER_LIMIT 32768

bool prime[UPER_LIMIT]; /* In fact in can be an array of bool in C++
,using pascal it even cost only 1000 bits */

int main()
{
	int primeIndex,anotherIndex;
	int d,i,c;

/* Initialize*/
	for(primeIndex = 2;primeIndex < UPER_LIMIT;primeIndex++)
		prime[primeIndex] = 1;

/* Check */
	for(primeIndex = 2;primeIndex <= sqrt(UPER_LIMIT);primeIndex++)
	{
		if(prime[primeIndex])
		{
			anotherIndex = primeIndex * 2;
			while(anotherIndex < UPER_LIMIT)
			{
				prime[anotherIndex] = 0;
				anotherIndex += primeIndex;
			}
	} 
} 

/* I / O */	
	while(scanf("%d",&d)==1 && d)
	{
		if(!d)
			break;
		for(c=0,i=2; i <= d/2; i++)
		{
			if(prime[i] && prime[d-i])
				c++;
		}
		printf("%d\n",c);
	}

	return 0;
}