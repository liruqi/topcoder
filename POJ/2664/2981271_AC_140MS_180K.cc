#include <string.h>

#include <stdio.h>

#define MAXN 10000

char S[MAXN];

int k,m,r,c,i,j,t;

int main(){

	while(scanf("%d",&k), k>0){
		char mdr=1;

		memset(S,0,MAXN);
		scanf("%d",&m);
		for(i=k;i;i--)
			scanf("%d",&t),S[t]=1;

		for(i=1;i<=m;i++)

		{
			int cnt=0;

			scanf("%d%d",&c, &r);
			for(j=1;j<=c;j++)scanf("%d",&t),cnt+=S[t];
			if(cnt<r)mdr=0;

		}
		puts(mdr?"yes":"no");

	}

}
