#include<string.h>
int r,c,T,m,ks;
int vst[26][26];
char stk[2000],top;
int dir[][2]={
	{-1,-2},
	{1,-2},
	{-2,-1},
	{2,-1},
	{-2,1},
	{2,1},
	{-1,2},
	{1,2}
};

int vld(int p,int q){return (p>=0&&q>=0)&&(p<r&&q<c);}

int dfs(int x,int y,int dep){
	int i,j;
	vst[x][y]=1;
	dep++;
	if(dep==m){
		stk[top++]='A'+y;
		stk[top++]='1'+x;
		return 1;
	}
	for(i=0;i<8;i++){
		int p=x+dir[i][0];
		int q=y+dir[i][1];
		if(vld(p,q) && !vst[p][q] && dfs(p,q,dep)){
			stk[top++]='A'+y;
			stk[top++]='1'+x;
			return 1;
		}
	}
	vst[x][y]=0;
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		int i;
		scanf("%d%d",&r,&c);
		printf("Scenario #%d:\n",++ks);
		m=r*c;top=0;
		memset(vst,0,sizeof(vst));
		for(i=0;i<m && !dfs(i/c,i%c,0);i++);
		if(top){
			for(i=top;i;i-=2){
				putchar(stk[i-2]);
				putchar(stk[i-1]);
			}
			puts("");
		}
		else 
			puts("impossible");
		puts("");
	}
}
