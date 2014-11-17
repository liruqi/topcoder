#include <stdio.h>
#include <string.h>
const int maxn=101;

char B[maxn];
int bl;
int A[maxn][maxn];

void pcp(char c){
	switch(c){
		case '(':
		case ')':
			putchar('(');
			putchar(')');
			return;
		case '[':
		case ']':
			putchar('[');
			putchar(']');
			return;
	}
}

bool pair(char l, char r)
{
	if(l=='(' && r==')') return true;
	if(l=='[' && r==']') return true;
	return false;
}

void find(int i, int j)
{
	int k;
	if( pair(B[i], B[j]) ) {
		A[i][j]=A[i+1][j-1];
	}
	else {
		A[i][j]=A[i][i]+A[i+1][j];
	}
	for(k=i; k<j; k++)
	{
		if(A[i][k]+A[k+1][j] < A[i][j])
		{
			A[i][j] = A[i][k]+A[k+1][j];
		}
	}
}

void print(int i, int j)
{
	if(i>j) return;
	if(i==j ) {
		pcp(B[i]);
		return;
	}
	if(pair(B[i], B[j]) && A[i][j] == A[i+1][j-1])
	{
		putchar(B[i]);
		print(i+1, j-1);
		putchar(B[j]);
		return;
	}
	int k;
	for(k=i; k<=j; k++)
	{
		if(A[i][k]+A[k+1][j] == A[i][j])
		{
			print(i, k);
			print(k+1, j);
			return ;
		}
	}
}
int main()
{
	int i,j,d;
	gets(B);
	bl=strlen(B);
	for(i=0; i<bl; i++)
		A[i][i]=1;
	for(d=1; d<bl; d++)
		for(i=0, j=i+d; j<bl; i++, j++)
			find(i, j);

	print(0, bl-1);puts("");
	
	return 0;
}
