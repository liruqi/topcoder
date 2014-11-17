#include <stdio.h>
int a,b,c,d;
inline int Cube(int x){return x*x*x;}
int main()
{
 	int N;
 	scanf("%d",&N);
 	for(a=5; a<=N; a++)
	for(b=2; b<a-2; b++)
	for(c=b; c<a-1; c++)
	for(d=c; d<a; d++)
		if(Cube(a)==Cube(b)+Cube(c)+Cube(d))
		printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
	scanf("%d",&N);
	return 0;
}
