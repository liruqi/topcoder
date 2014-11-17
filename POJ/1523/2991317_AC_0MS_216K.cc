#include <stdio.h>
#include <list>
using namespace std;

typedef list<int> lit;
typedef lit::iterator lii;
const int maxn = 1001;
lit adj[maxn];

int dis[maxn];
int fin[maxn];
int tme;
int cnt[maxn];
int lul[maxn];
bool vst[maxn];

void dfs(int u){//get dis and finish time
	vst[u]=1;
	tme++;
	dis[u]=tme;
	for(lii it=adj[u].begin(); it!=adj[u].end(); it++)
		if(!vst[*it])
			dfs(*it);
	tme++;
	fin[u]=tme;
}

int lga(int u){
	int ret = dis[u];
	vst[u]=1;
	for(lii it=adj[u].begin(); it!=adj[u].end(); it++)
	{
		int v=*it;
		if(vst[v]){
            ret <?= dis[v];
            continue;
        }
		int t=lga(v);
		ret <?= t;
		if(dis[u]<=t)
			cnt[u]++;
	}
	return ret;
}

int main(){
	int u,v,i,ks=1;
	while(scanf("%d",&u) == 1, u){
		for(i=0;i<maxn;i++)
			adj[i].clear();
		memset(dis,0xff,sizeof(dis));
		memset(fin,0xff,sizeof(dis));
		memset(lul,0,sizeof(lul));
		memset(cnt,0,sizeof(cnt));
		do{
			scanf("%d",&v);
			//printf("%d %d\n",u,v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}while(scanf("%d",&u), u>0);
		u=1;
		tme=0;
		memset(vst,0,sizeof(vst));
		dfs(u);
		memset(vst,0,sizeof(vst));
		lga(u); cnt[u]--;
		printf("Network #%d\n",ks++);
		bool ext=0;
		for(i=1;i<maxn;i++)if(cnt[i]>0){ 
			ext=1;
			printf("  SPF node %d leaves %d subnets\n", i, cnt[i]+1);
		}
		if(!ext)puts("  No SPF nodes");
		puts("");
	}
}
/*
1 2
2 3
1 3
3 4
0
0
*/
