#include <stdio.h>
#include <string.h>

int n,k,i,j,cnt;
char cb[10][10];
char us[10];
void dfs(int d,int c){
	if(c==0) {cnt++;return;}
	if(d>n) return;
	if(c>0){
		int i;
		for(i=0;i<n;i++)if(cb[d][i]=='#'&&!us[i]){
			us[i]=1;dfs(d+1,c-1);us[i]=0;
		}
	}
	dfs(d+1,c);
}

int main(){
	while(~scanf("%d%d",&n,&k)&&n>=0){
		for(cnt=i=0;i<n;i++)scanf("%s",cb[i]);
		memset(us,0,sizeof(us)),dfs(0,k);
		printf("%d\n",cnt);
	}
}
