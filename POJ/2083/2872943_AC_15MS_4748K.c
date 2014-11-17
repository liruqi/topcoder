#include <stdio.h>
#include <string.h>

#define maxn 2187
char F[maxn][maxn];
int P[10];
void copy(int n){
int i;
for(i=0;i<n;i++)
	memcpy(F[n+i]+n, F[i], n),memcpy(F[i]+2*n, F[i], n),memcpy(F[2*n+i],F[i],3*n);
}

void out(int n){
int i,j;
for(i=0;i<n;i++){for(j=0;j<n;j++)putchar(F[i][j]);puts("");}
puts("-");
}

int main(){
int i,j;
memset(F,' ',sizeof(F));F[0][0]='X';
for(P[0]=1,i=1;i<8;i++) P[i]=P[i-1]*3;
for(i=1;i<7;i++) copy(P[i-1]);
while(~scanf("%d",&i)&&i>0) out(P[i-1]);
}