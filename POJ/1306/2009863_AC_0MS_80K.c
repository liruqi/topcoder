#include <stdio.h>

int main()
{
	int M,N,i;
	double r;
	while(scanf("%d%d",&N,&M)!=EOF && N){
		printf("%d things taken %d at a time is ",N,M);
		if(M*2 > N)
		    M = N-M;
		    r=1;
		    for(i=N-M+1; i<=N; i++)
		        r*=i;
		    for(i=M; i>1; i--)
		    	r/=i;
			printf("%.0f exactly.\n",r);
	}
	return 0;
}
