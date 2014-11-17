#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)==1) 
	{
		int i;
		int maxday, mv = -1;
		if (n == 0) 
			break;
		for (i = 1; i <= n; i++) {
			int a, b;
			scanf("%d %d", &a,&b);
			if(a+b>8)
			{
				if(a+b>mv)
				{ mv=a+b; maxday = i;}
			}			
		}
		if (mv <= 8) printf("0\n");
		else printf("%d\n", maxday);
	}
	return 0;
}