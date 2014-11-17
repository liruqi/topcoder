#include <stdio.h>

int A[33][61][61];
int n, m;
int T[61][61];

void mmultip(int cp, int p1, int p2){
	int i,j,k;
	
	for(i=1; i<=2*n; i++)
	{
		for(j=1; j<=2*n; j++)
		{
			T[i][j]=0;
			for(k=1; k<=2*n; k++)
			{	
				T[i][j] += A[p1][i][k]*A[p2][k][j];
				T[i][j] %= m;
			}
		}
	}
	for(i=1; i<=2*n; i++)
		for(j=1; j<=2*n; j++)
			A[cp][i][j]=T[i][j];
}

int main(){
	int k;
	int j,i,p;
	scanf("%d%d%d",&n, &k, &m);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
		{
			scanf("%d", A[0][i]+j);
			A[0][i][j+n]=A[0][i][j];
		}
	}

	for(i=1; i<=n; i++)
		A[0][n+i][n+i]=1;
	
	for(i=1; i<32; i++)
		mmultip(i, i-1, i-1);
	
	for(i=1; i<=2*n; i++)
		A[32][i][i]=1;
	
	while(k)
	{
		p=__builtin_ctz(k);
		mmultip(32, p, 32);
		k-=(k&-k);
	}
		
	for(i=1; i<=n; i++)
	{
		for(j=1; j<n; j++)
		printf("%d ",A[32][i][j+n]%m);
		printf("%d\n",A[32][i][j+n]%m);
	}
	return 0;
}

