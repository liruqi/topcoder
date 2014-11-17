#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=10001;
int N,M;
vector<int> adj[maxn],rev[maxn];
int nds[maxn],fin[maxn],tme;
bool vst[maxn];
int color[maxn], cnt[maxn];

set<int> scc[maxn];

int top;

void dfs_vst(int u){
	int i;
	vst[u]=1;
	for(i=0;i<adj[u].size();i++)
		if(!vst[adj[u][i]])
			dfs_vst(adj[u][i]);
	fin[u]=tme++;
}

void dfs_get_ft(){
	int u;
	memset(vst,0,sizeof(vst));
	tme=0;
	for(u=1;u<=N;u++) if(!vst[u]) dfs_vst(u);
}

void dfs_collect(int u){
	int i;
	vst[u]=1;
	color[u]=top;
	cnt[top]++;
	for(i=0;i<rev[u].size();i++)
		if(!vst[rev[u][i]])
			dfs_collect(rev[u][i]);
}

void dfs_get_scc(){
	int u,i;
	memset(vst,0,sizeof(vst));
	memset(cnt,0,sizeof(cnt));
	top=0;
	for(i=0;u=nds[i],i<N;i++) if(!vst[u]){
		top++;
		dfs_collect(u);
	}
}

int solve(){
	int u,i;
	for(u=1;u<=N;u++){
		for(i=0;i<rev[u].size();i++)
		{
			scc[ color[u] ].insert( color[rev[u][i]] );
		}
	}
	memset(vst,0,sizeof(vst));
	vst[top]=1;
	for(u=top-1;u>=1;u--){
		for(set<int>::iterator it=scc[u+1].begin();it!=scc[u+1].end();++it)
			vst[*it]=1;
		if(!vst[u])
			return 0;
	}
	return cnt[top];
}

bool cmp(int p,int q){
	return fin[p]>fin[q];
}

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	int u,v,i;
	for(i=0;i<M;i++){
		scanf("%d",&u);
		scanf("%d",&v);
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	dfs_get_ft();
	for(i=0;i<N;i++) nds[i]=i+1;
	sort(nds,nds+N,cmp);
	dfs_get_scc();
	printf("%d\n",solve());
}
