#include<stdio.h>
#include<queue>
#include<list>
using namespace std;
#define inf 0x0f0f0f0f
int n, m, speed;
struct node{
	int x,y;
}na[50010];
struct edge{
	int u,v,w;
}ea[200010];

typedef long long ll;
typedef list<int> lit;
typedef lit::iterator lii;

int d[50010];
bool vst[50010];
ll rel[50010];
list<int> adj[50010];
struct cmp{
	bool operator()(node p,node q){
		return p.y>q.y;
	}
};

void solve(){
	int i;
	
	for(i=1;i<=n;i++) adj[i].clear(),scanf("%d%d",&na[i].x,&na[i].y);
	for(i=0;i<m;i++)
		scanf("%d%d%d",&ea[i].u,&ea[i].v,&ea[i].w);
	scanf("%d%d",&na[0].x,&na[0].y);
	scanf("%d%d",&na[n+1].x,&na[n+1].y);
	
	for(i=0;i<=n+1;i++) {
		ll dx=na[i].x-na[0].x;
		ll dy=na[i].y-na[0].y;
		rel[i]=dx*dx+dy*dy;
	}
	
	for(i=0;i<m;i++){
		int u,v,w;
		u=ea[i].u;
		v=ea[i].v;
		w=ea[i].w;
		ll dd=rel[u]-rel[v];
		if(v==n+1) dd=-1;
		else if(u==n+1) dd=1;
		if(dd<0)
			adj[u].push_back(i);
		else if(dd>0)
			adj[v].push_back(i);
	}

	memset(d,0x0f,sizeof(d));
	memset(vst,0,sizeof(vst));
	d[0]=0;
	priority_queue<node,vector<node>,cmp> pq;
	pq.push((node){0,0});
	while(!pq.empty()){
		node u=pq.top(); pq.pop();
		if(!vst[u.x]){
			vst[u.x]=1;
			for(lii it=adj[u.x].begin(); it!=adj[u.x].end(); ++it){
				edge &c= ea[*it];
				int v = c.u + c.v - u.x;
				int can = d[u.x] + c.w;
				ll ed=can * speed;
				if(d[v]>can && ed*ed < rel[v])
				{
					d[v] = can;
					pq.push((node){v,can});
				}
			}
		}
	}
	if(d[n+1]==inf)	puts("Impossible");
	else printf("%d\n",d[n+1]);
}

int main(){
	while(3==scanf("%d%d%d",&n,&m,&speed)) solve();
}
