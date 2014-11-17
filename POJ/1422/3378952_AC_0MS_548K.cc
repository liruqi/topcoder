/*
prob:	poj1422
algo:	min path cover = number of node - max match 
author:	liruqi
date:	2008-5-4
*/
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
#include<set>

using namespace std;
#define max_node 510
bool adj[max_node][max_node],vst[max_node];
int left_num,right_num,n,m;
int match[max_node];

int dfs(int p){
	int v,t;
	for(v=1;v<=right_num;v++) if(!vst[v] && adj[p][v]){
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
		if(!n && !m) break;
		
		memset(adj,0,sizeof(adj));
		memset(match,0,sizeof(match));

		for(i=1;i<=m;i++){
			scanf("%d",&u);
			scanf("%d",&v);
			adj[u][v]=1;
			//adj[v][u]=1;
		}
		int cnt=0;
		left_num=n;
		right_num=n;
		for(i=1;i<=left_num;i++){
			memset(vst,0,sizeof(vst));
			cnt+=dfs(i);
		}
		printf("%d\n",(n-cnt));
	}
}

