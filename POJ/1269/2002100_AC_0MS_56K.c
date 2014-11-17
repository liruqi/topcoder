/*
 * The algorithm is found in TopCoder
 */
#include <stdio.h>
int i,j;
int x1[2],y1[2],x2[2],y2[2],A[2],B[2],C[2];

int main()
{
	int n;
	scanf("%d",&n);
	puts("INTERSECTING LINES OUTPUT");
	while(n--)
	{
	 	double det;  
		for(i=0;i<2;i++)
		{
			scanf("%d%d%d%d",(x1+i),(y1+i),(x2+i),(y2+i));
			A[i]=y2[i]-y1[i];
			B[i]=x1[i]-x2[i];
			C[i]=A[i]*x1[i]+B[i]*y1[i];
		}
		det=A[0]*B[1] - A[1]*B[0];
		if(det==0)
		{
		//	if( (A[1] && A[1]*C[0]==A[0]*C[1])||(B[1] && B[1]*C[0]==B[0]*C[1]) )
			if(A[0]*x1[1]+B[0]*y1[1]==C[0] && A[0]*x2[1]+B[0]*y2[1]==C[0])
				puts("LINE");
			else
				puts("NONE");
		}
		else
		{
			double a=(B[1]*C[0] - B[0]*C[1])/det;
			double b=(A[0]*C[1] - A[1]*C[0])/det;
			printf("POINT %.2lf %.2lf\n",a,b);
		}
	}
	puts("END OF OUTPUT");
	scanf("%d",&n);
	return 0;
}
