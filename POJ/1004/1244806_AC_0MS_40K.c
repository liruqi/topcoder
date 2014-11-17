#include<stdio.h>
int main()
{
	float f,aver,sum = 0;
	int i;
	for(i = 0; i < 12; i++)
	{
		scanf("%f",&f);
		sum += f;
	}
	aver = sum/12;
	printf("%c",36);
	printf("%.2f",aver);
		
	return 0;
}

