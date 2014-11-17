#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
char seg[11][22];
int len[11];
int idx[11];
int dis[11][11];
int comblen(int p, int q){
	int i,j,L;
	char *s1=seg[p],*s2=seg[q];
	L=len[p];
	for(i=0;i<L;i++)
		if(strncmp(s1+i, s2, L-i)==0)
			return L-i;
	return 0;
}

int findlen(){
	int i,j,red=0;
	for(i=1;i<N;i++)
		red += dis[idx[i]][idx[i+1]];
	//printf("＊%d\n",red);
	return red;
}

int main()
{
	int i,j,T;
	scanf("%d",&T);
	while(T--){
		int maxred = 0, orglen=0;
		memset(seg, 0, sizeof(seg));
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%s",seg[i]);
			idx[i]=i;
			len[i]=strlen(seg[i]);
			//printf("len: %d\n",len[i]);
			orglen += len[i];
		}
		//L=strlen(seg[1]);
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)if(i!=j)
				dis[i][j]=comblen(i,j);//,printf("%d-%d: %d\n",i,j,dis[i][j]);
		
		do{
			maxred >?= findlen();
		}while(next_permutation(idx+1,idx+1+N));
		printf("%d\n",orglen-maxred);
	}
	return 0;
}	
