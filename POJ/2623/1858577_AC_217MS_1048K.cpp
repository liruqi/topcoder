#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

uint d[250001], n;

int main()
{
	while (scanf("%u",&n)!=EOF)
	{
		int i;
		for (i = 0; i < n; i++) 
			scanf("%u", d+i);
		sort(d, d+n);		//call lib function
		if (n % 2 == 1)
			printf("%.1f\n", (float) d[n/2]);
		else 
			printf("%.1f\n", (float) (d[n/2]+d[n/2-1])/2.0);
	}
}