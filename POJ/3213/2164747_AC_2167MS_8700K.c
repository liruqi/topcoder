#include <stdio.h>
#define maxn 1001
int A[maxn][maxn];	
int B[maxn][maxn];	
int C[maxn][maxn];	
int N,P,M, val;

void in()
{
	int i, j;
	scanf("%d %d %d", &N, &P, &M);

	for(i=1; i<=N; i++)
	for(j=1; j<=P; j++)
	scanf("%d", A[i]+j);

	for(i=1; i<=P; i++)
	for(j=1; j<=M; j++)
	scanf("%d", B[i]+j);

	for(i=1; i<=N; i++)
	for(j=1; j<=M; j++)
	scanf("%d", C[i]+j);
}

int findRowError(){
	int i,j;
	int BR[maxn], sm, sop;
	for(i=1; i<=P; i++)
	{
		sm=0;
		for(j=1; j<=M; j++)
			sm+=B[i][j];
		BR[i]=sm;
	}
	for(i=1; i<=N; i++)
	{
		sop=0;
		for(j=1; j<=P; j++)
			sop+=A[i][j]*BR[j];
		sm=0;
		for(j=1; j<=M; j++)
			sm+=C[i][j];
		if(sop!=sm) return i;
	}
	return 0;
}

int findColError(int r)
{
	int i, j;
	for(i=1; i<=M; i++)
	{
		val=0;
		for(j=1; j<=P; j++)
			val+=A[r][j]*B[j][i];
		if(val!=C[r][i]) return i;
	}
	return 0;
}

int main()
{
	
	int col, row;in();row=findRowError();
	if(row)
	{
		col=findColError(row);
		puts("No");
		printf("%d %d\n%d\n", row, col, val);
	}
	else
		puts("Yes");
	return 0;
}
