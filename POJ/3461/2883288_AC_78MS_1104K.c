#include <stdio.h>
#include <stdlib.h>
#define maxt 1001000
#define maxp 10010

char P[maxp];
char T[maxt];
int L[maxt];
int n,m;

void prefixF(){
	int k=0,q;
	L[1]=0;
	for(q=2;q<=m;q++)
	{
		while(k>0 && P[k+1]!=P[q])
			k=L[k];
		if(P[k+1]==P[q])
			k++;
		L[q]=k;
	}
}

int kmp(){
	int i,q=0,cnt=0;
	prefixF();
	for(i=1;i<=n;i++){
		while(q>0 && P[q+1]!=T[i])
			q=L[q];
		if(P[q+1]==T[i])
			q++;
		if(q==m){
			cnt++;
			q=L[q];
		}
	}
	return cnt;
}

int main(){
	int tc;scanf("%d\n",&tc);
	while(tc--){
		gets(P+1);
		m=strlen(P+1);
		gets(T+1);
		n=strlen(T+1);
		printf("%d\n",kmp());
	}
}
