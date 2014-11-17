short min(short x, short y)
{ return x<y ? x : y; }
char S[5001];
short C[2][5001];
main()
{
    int N, i, j, k=0;
	scanf("%d%s", &N, S);
	for(i=N-2; i>=0; i--)
	{
        k=!k;
        for(j=i+1; j<N; j++)
        {
            if(S[i]==S[j]) C[k][j]=C[!k][j-1];
            else C[k][j]=min(C[k][j-1], C[!k][j])+1;
        }
    }
    printf("%d\n", C[k][N-1]);
}


