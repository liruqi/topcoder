int max(int x, int y)
{
	return x>y ? x : y;
}
int N, i, j;
int A[351][351];

int main()
{
	scanf("%d", &N);
	for(i=1; i<=N; i++)
		for(j=1; j<=i; j++)
			scanf("%d", A[i]+j);
	for(i=N-1; i>0; i--)
		for(j=1; j<=i; j++)
			A[i][j] += max(A[i+1][j], A[i+1][j+1]);
	printf("%d",A[1][1]);
	return 0;
}
