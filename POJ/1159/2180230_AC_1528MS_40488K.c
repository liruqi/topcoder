#include <stdio.h>

short min(short x, short y)
{ return x<y ? x : y; }

#define maxn 5001
char S[maxn];
short C[maxn][maxn];
int N;

int main()
{
    int d, i, j;
	scanf("%d%s", &N, S);
	for(i=N-2; i>=0; i--)
	{
        for(j=i+1; j<N; j++)
        {
            if(S[i]==S[j])
                C[i][j]=C[i+1][j-1];
            else        //S[i]!=S[j]
                C[i][j]=min(C[i][j-1], C[i+1][j])+1;
        }
    }
    printf("%d\n", C[0][N-1]);
    return 0;
}
