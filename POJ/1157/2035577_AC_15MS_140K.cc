#include <stdio.h>

int A[101][101];
int M[102][102];
int F,V;

int main(){
	int i,j;
	scanf("%d%d",&F,&V);
	for(i=1; i<=F; i++)
		for(j=1; j<=V; j++)
			scanf("%d",A[i]+j);
	for(i=F; i>0; i--){
		j=V-F+i;
		M[i][j]=A[i][j]+M[i+1][j+1];
		for(j--; j>=i; j--)
			M[i][j]=(A[i][j]+M[i+1][j+1]>M[i][j+1])?A[i][j]+M[i+1][j+1]:M[i][j+1];
	}
	printf("%d",M[1][1]);
	return 0;
}

