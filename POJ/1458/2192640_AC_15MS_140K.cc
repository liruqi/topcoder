#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=250;
short A[maxn][maxn];
char X[maxn], Y[maxn];
int main()
{
	int xl, yl;
	int i, j;
	while(scanf("%s%s", X+1, Y+1)!=EOF)	{
		xl=strlen(X+1);
		yl=strlen(Y+1);
		for(i=0; i<=xl && i<yl; i++) {
			A[0][i]=0;
			A[i][0]=0;
		}
		for(i=1; i<=xl; i++)
			for(j=1; j<=yl; j++) {
				if(X[i]==Y[j])
					A[i][j] = A[i-1][j-1]+1;
				else
					A[i][j] = max(A[i-1][j], A[i][j-1]);
			}

		printf("%d\n",A[xl][yl]);
	}
	return 0;
}
