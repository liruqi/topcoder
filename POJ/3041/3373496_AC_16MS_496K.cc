//3041
#include<stdio.h>
#include<vector>

char ast[510][510],vst[510];
int match[510];

int N;

int dfs(int p){
	for(int c=1;c<=N;c++) if(!vst[c]&&ast[p][c]){
		vst[c]=1;
		if(match[c]==-1 || dfs(match[c])){
			match[c]=p;
			return 1;
		}
	}
	return 0;
}

int slv(){
	int cnt=0,i;
	memset(match,-1,sizeof(match));
	memset(vst,  0, sizeof(vst));
	for(i=1;i<=N;i++){
		memset(vst,0,sizeof(vst));
		cnt+=dfs(i);
	}
	return cnt;
}

int main(){
	int r,c,k;
	scanf("%d",&N);
	scanf("%d",&k);
	
	while(k--){
		scanf("%d",&r);
		scanf("%d",&c);
		ast[r][c]=1;
	}
	printf("%d\n",slv());
}
