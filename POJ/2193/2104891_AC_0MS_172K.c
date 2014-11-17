#include <stdio.h>
int N,M;
__int64 A[11][2001];
int main()
{
 	int tc=1; 	
	int i,j; 
	for(i=1; i<=2000; i++)
	A[1][i]=i;
	for(i=2; i<=10; i++)
	{
		for(j = 1<<(i-1); j<=2000; j++)
		{
		 	A[i][j]+=A[i][j-1]+A[i-1][j/2];
	    }
	}
        scanf("%d",&N);
 	while(scanf("%d%d",&N,&M)!=EOF)
		printf("Case %d: n = %d, m = %d, # lists = %I64d\n",tc++, N, M, A[N][M]);
	return 0;
}
