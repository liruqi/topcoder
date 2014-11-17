#include <iostream>
#include <queue>
#include <list>
#define maxn 110
using namespace std;

typedef struct _node{
	int v,w;
}node;
typedef list<node> lit;
typedef lit::iterator lii;
lit adj[maxn];
bool vst[maxn];
int n,e;

struct cmp{
	bool operator()(node p,node q){
		return p.w>q.w;
	}
};

int main(){
	int ks,i,u,v,w;
	node nd;
	cin>>ks;
	while(ks-- && cin>>n>>e){
		for(i=1;i<=n;i++) 
			adj[i].clear();
		for(i=e;i;i--){
			cin>>u>>v>>w;
			nd.w=w;
			nd.v=v;
			adj[u].push_back(nd);
			nd.v=u;
			adj[v].push_back(nd);
		}
		//prim
		memset(vst,0,sizeof(vst));
		priority_queue<node, vector<node>, cmp> pq;
		int total_cost=0;
		bool unique=true;
		nd.v=1;
		nd.w=0;
		pq.push(nd);
		while(!pq.empty() && unique){
			nd = pq.top();
			int u=nd.v;
			int min_weight=0x7fffffff;
			pq.pop();
			if(vst[u]) continue;
			total_cost += nd.w;
			//cout<<u<<endl;
			vst[u]=true;
			for(lii it=adj[u].begin(); it!=adj[u].end(); ++it){
				pq.push(*it);
				unique=true;
				if(it->w < min_weight)
					min_weight = it->w;
				else if(it->w == min_weight)
					unique=false;
			}
		}
		if(unique) cout<<total_cost<<endl;
		else puts("Not Unique!");
	}
	return 0;
} 