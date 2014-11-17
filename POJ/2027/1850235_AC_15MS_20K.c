#include <stdio.h>
int x,y,n;
int main(void)
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		if(x>=y)
			puts("MMM BRAINS");
		else 
			puts("NO BRAINS");
	}
	return 0;
}