#include<stdio.h>
void main()
{
	int N,i;
	scanf("%d",&N);
	for(i = 0;i < N;i++)
	{
		float x,y;
		int year = 0;
		scanf("%f%f",&x,&y);
		for(;;year++)
			if(year*100 > 3.14159*(x*x + y*y))
			{
				printf("Property %d:",i+1);
			    printf(" This property will begin eroding in year %d.\n",year);
				break;
			}
	}
	printf("END OF OUTPUT.");
}





	