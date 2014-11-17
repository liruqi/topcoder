#include <stdio.h>
#include <stdlib.h>

#define m(x,y) x > y ? x : y
int main()
{
	int row,i,j;
	int * t;
	scanf("%d",&row);
	
	t=(int *)malloc(row*row*sizeof(int));

	for(i=0; i<row; i++)
		for(j=0;j<=i;j++)
			scanf("%d",&t[i*row + j]);

	for(i=row-1;i>0;i--)
		for(j=0;j<i;j++)
			t[(i-1)*row + j] += m(t[i*row + j],t[i*row + j + 1]);
	printf("%d",t[0]);

	return 0;
}