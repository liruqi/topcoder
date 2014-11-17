/*
PKU3159 SSSP
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef VI::iterator VII;
typedef VS::iterator VSI;


#define EPS 1e-9
#define PI_2 (M_PI*2.0)
#define INF 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))
#define pb push_back


/*node size*/
const int node_sz=30008;
const int edge_sz=150000;

typedef int val_type;
const int inf=0x7fffffff;
struct edge{
	int t,w;
	edge *link;
	edge(int a,int b):t(a),w(b){}
	edge(){link=0;}
};
struct cmp{
    bool operator()(edge p,edge q){return p.w>q.w;}
};
edge mem[edge_sz];


struct Graph{
	int node_n;
	edge* adj[node_sz];
	edge* top;
	val_type dist[node_sz];
	void add(int s,int t,int w)
	{
		top->t=t;
		top->w=w;
		top->link=adj[s];
		adj[s] = top;
		top++;
	}
	
	void dijkstra(){
		int sour = 1;
		fill(dist, dist+node_n+1, inf);
		dist[sour]=0;
		priority_queue<edge,vector<edge>,cmp> pq;
		pq.push(edge(sour,0));
		while(!pq.empty()){
			edge now=pq.top();
			pq.pop();
			if(now.w>dist[now.t]) continue;
			//VE &e=adj[now.t];
			edge* it = adj[now.t];
			for(; it; it=it->link)	{
				val_type can=dist[now.t]+it->w;
				if(can<dist[it->t]){
					dist[it->t]=can;
					pq.push(edge(it->t,can));
				}
			}
		}
	}
	void init()
	{
		int edge_n;
		ni(node_n);
		ni(edge_n);
		int s,t,w;
		top = mem;
		
		for(int k=edge_n; k; k--)
		{
			ni(s); ni(t); ni(w);
			//adj[s].push_back( edge(t,w) );
			add(s,t,w);
		}
	}
	void out()
	{
		printf("%d\n", dist[node_n]);
	}
} g;

int main()
{
	g.init();
	g.dijkstra();
	g.out();
}
