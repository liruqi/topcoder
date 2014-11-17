#include <stdio.h>

int A[100];
int N;
int main()
{
 	int i=0,j,t;
 	scanf("%d", &N);
 	for(; i<N; i++)
	 	for(j=0; j<N; j++)
	 	{
		 	scanf("%d", &t);
		 	if(t==3)
		 	A[i]++;
		}
	t=0;
	for(i=1; i<N; i++)	
	    if(A[i]>A[0])
	    {
		 	A[0]=A[i];
	        t=i;
		}
	printf("%d", t+1);
	return 0; 
}
