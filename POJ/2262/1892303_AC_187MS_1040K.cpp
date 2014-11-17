#include <stdio.h>
#include <string.h>
#define MS 1000001
bool odd[MS];   
int main()
{
	int i, j;
	int x;
	memset(odd, true, sizeof(odd));
	
	for(i = 2; i <= MS/2; i++)
	{
		if(odd[i])
		{
			for(j = 2; i * j < MS; j++)
			{
				odd[j * i] = false;
			}
		}
	}
	
	scanf("%d", &x);
	while(x > 0)
	{
		for(i = 3; i <= x/2; i += 2)
		{
			if(odd[i] && odd[x-i])
			{
				break;
			}
		}
		printf("%d = %d + %d\n", x, i, x-i);
		scanf("%d", &x);
	}
	return 0;
}
