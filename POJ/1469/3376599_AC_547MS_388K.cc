/*
prob:	poj1469
algo:	max match / perfect match
author:	liruqi
date:	2008-5-3
*/
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
#include<set>

using namespace std;

bool adj[310][310],vst[310];
int c_num,s_num;
int match[310],dgr[310];

int dfs(int p){
	int v,t;
	for(v=1;v<=s_num;v++) if(!vst[v] && adj[p][v]){
		t=match[v];
		vst[v]=1;
		if(t==0 || dfs(t)){
			match[v]=p;
			return 1;
		}
	}
	return 0;
}

int main(){
	int i,j,k,ks;
	scanf("%d",&ks); 
	while(ks--){
		scanf("%d",&c_num);
		scanf("%d",&s_num);

		memset(adj,0,sizeof(adj));
		memset(match,0,sizeof(match));
		
		for(i=1;i<=c_num;i++){
			scanf("%d",&dgr[i]); 
			for(k=1;k<=dgr[i];k++){
				scanf("%d",&j);
				adj[i][j]=1;
			}
		}
		int cnt=0;
		for(i=1;i<=c_num;i++){
			memset(vst,0,sizeof(vst));
			cnt+=dfs(i);
		}
		puts((c_num-cnt)?"NO":"YES");
	}
}
