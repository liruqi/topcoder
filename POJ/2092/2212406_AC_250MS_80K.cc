#include <stdio.h>
#include <memory.h>
const int maxn=10001;
int A[maxn];

int main()
{
	int N, M, i, j, t;
	int ft, sd;
	while(scanf("%d%d",&N,&M) && N){
		memset(A, 0, maxn<<2);
		for(i=0; i<N; i++)
		for(j=0; j<M; j++){
			scanf("%d",&t);
			A[t]++;
		}
		ft=0; sd=0;
		for(i=1; i<maxn; i++)
		{
			if(A[ft]<A[i])
			{
				sd=ft;
				ft=i;
			}
			if(A[ft]>A[i])
				if(A[sd]<A[i])
					sd=i;
		}
		for(i=1; i<maxn; i++)
			if(A[i]==A[sd])
				printf("%d ",i);
				puts("");
	}
	
	return 0;
}
