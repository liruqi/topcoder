/*
	may 22 07
	author: liruqi
*/
#include <stdio.h>

int main()
{
	int n;
	do{
		int sn, i;
		scanf("%d",&n);
		if(n==0) break;
		printf("Printing order for %d pages:\n", n);
		sn=(n+3)/4;
		switch(n%4)
		{
			case 0:
				i=1;
				break;
			case 1:
				i=3;
				puts("Sheet 1, front: Blank, 1");
				if(sn==1)
					continue;
				printf("Sheet 1, back : 2, Blank\n");
				printf("Sheet 2, front: Blank, 3\n");
				printf("Sheet 2, back : 4, %d\n", n);
				break;
			case 2:
				i=2;
				puts("Sheet 1, front: Blank, 1");
				puts("Sheet 1, back : 2, Blank");
				break;
			case 3:
				i=2;
				puts("Sheet 1, front: Blank, 1");
				printf("Sheet 1, back : 2, %d\n", n);
				break;
			default:
				i=1;
		}
		for(; i<=sn; i++)
		{
			printf("Sheet %d, front: %d, %d\n",i, 4*sn+2-2*i, i*2-1);
			printf("Sheet %d, back : %d, %d\n", i, i*2 ,4*sn+1-2*i);
		}
	}while(1);
	return 0;
}
