#include <stdio.h>

#define maxn 1000
int N,A[maxn][maxn];

int judge()
{
	int i, j;
	for(i=N-2; i>=0; i--)
		for(j=N-2; j>=0; j--)
		{
			if(A[i][j]+A[i+1][j+1]!=A[i+1][j]+A[i][j+1])
				return 0;
		}
	return 1;
}

void main()
{
	int i, j;
	while(scanf("%d",&N)!=EOF && N){
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				scanf("%d",A[i]+j);
			puts(judge() ? "homogeneous" : "not homogeneous");
	}
}