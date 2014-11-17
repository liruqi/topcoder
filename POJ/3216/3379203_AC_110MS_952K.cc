/*
prob:	poj3216
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
int match[max_node],pi[max_node],ti[max_node],di[max_node];
int wt[max_node][max_node];
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
	int i,j,k,u,v;
	while(1){
		scanf("%d",&m);
		scanf("%d",&n);
		if(!m)
			break;
		memset(adj,0,sizeof(adj));
		memset(match,0,sizeof(match));
		for(u=1;u<=m;u++)
			for(v=1;v<=m;v++)
				scanf("%d",wt[u]+v);
		for(k=1;k<=m;k++)
			for(u=1;u<=m;u++)if(wt[u][k]!=-1)
			for(v=1;v<=m;v++)if(wt[k][v]!=-1)
			{
				i=wt[u][k]+wt[k][v];
				if(wt[u][v]==-1 || wt[u][v]>i)
					wt[u][v]=i;
			}
		for(i=1;i<=n;i++){
			scanf("%d",&pi[i]);
			scanf("%d",&ti[i]);
			scanf("%d",&di[i]);
		}
		for(u=1;u<=n;u++)
			for(v=1;v<=n;v++){
				if(wt[u][v]!=-1 && (ti[u]+di[u]+wt[pi[u]][pi[v]] <= ti[v]))
					adj[u][v]=1;
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

