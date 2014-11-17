#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef VI::iterator VII;
typedef VS::iterator VSI;


#define eps 1e-9
#define PI_2 (M_PI*2.0)
#define inf 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))
#define pb push_back

/*node size*/
const int n_size=500;
typedef int val_type;

struct edge{
	int s,t,w;
	edge(int _s,int _t,int _w):s(_s),t(_t),w(_w){}
};
struct cmp{
    bool operator()(edge p,edge q){return p.w>q.w;}
};
struct Graph{
	typedef vector<edge> VE;
	VE es;//edge set
	int node_n;
	int edge_n;
	VE adj[n_size];
	val_type dist[n_size];
	
	void dijkstra(int sour){
		memset(dist,inf,sizeof(dist));
		dist[sour]=0;
		priority_queue<edge,vector<edge>,cmp> pq;
		pq.push(edge(0,sour,0));
		while(!pq.empty()){
			edge now=pq.top();
			pq.pop();
			if(now.w>dist[now.t]) continue;
			VE &e=adj[now.t];
			for(VE::iterator it=e.begin();it!=e.end();++it)	{
				val_type can=dist[now.t]+it->w;
				if(can<dist[it->t]){
					dist[it->t]=can;
					pq.push(edge(now.t,it->t,can));
				}
			}
		}
	}
	int init(){
		ni(node_n);
		ni(edge_n);
		if(!node_n) return 0;
		for(int it=edge_n;it;it--)
		{
			int s,t,w;
			ni(s), ni(t), ni(w);
			es.pb(edge(min(s,t),max(s,t),w));
			adj[s].pb(edge(s,t,w));
			adj[t].pb(edge(t,s,w));
		}
		return 1;
	}
	int solve()
	{
		int* mp = max_element(dist+1,dist+node_n+1);
		int ei=-1;
		int tm=-1;
		for(int i=0;i<es.size();i++)
		{
			int now=(dist[es[i].s]+dist[es[i].t]+es[i].w);
			//show(now);
			if(now>tm)
			{
				tm = now;
				ei = i;
			}
		}
		if(tm > (*mp)*2)
		{
			printf("The last domino falls after %d.%d seconds, between key dominoes %d and %d.\n", 
				   tm/2, (tm%2)?5:0, es[ei].s, es[ei].t);
		}
		else 
		{
			printf("The last domino falls after %d.0 seconds, at key domino %d.\n", 
				   *mp, (mp-dist));
		}
		puts("");
	}
};


int main(){
	int ks=1;
	while(1)
	{
		Graph g;
		if(!g.init()) break;
		g.dijkstra(1);
		cout<<"System #"<<ks++<<endl;
		g.solve();
	}
	return 0;
}
