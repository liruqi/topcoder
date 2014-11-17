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
int n,m;
int match[310];

int dfs(int p){
	int v,t;
	for(v=1;v<=n;v++) if(!vst[v] && adj[p][v]){
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
	int i,j,k,u,v,ks;
	scanf("%d",&ks); 
	while(ks--){
		scanf("%d",&n);
		scanf("%d",&m);

		memset(adj,0,sizeof(adj));
		memset(match,0,sizeof(match));
		
		for(i=1;i<=m;i++){
			scanf("%d",&u);
			scanf("%d",&v);
			adj[u][v]=1;
			adj[v][u]=1;
		}
		int cnt=0;
		for(i=1;i<=n;i++){
			memset(vst,0,sizeof(vst));
			cnt+=dfs(i);
		}
		puts((n-cnt)?"alice":"bob");
	}
}
