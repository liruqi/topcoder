#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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

template<class T>
void show(T x){ cout<< "# "<< x <<endl; }
template<class T>
void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef VI::iterator VII;
typedef VS::iterator VSI;

#define INF 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))
#define pb push_back

int node_n;
int edge_n;
int sour, dest;

struct edge{
	int next,cost,len;
};

#define MAXND 1108
typedef vector<edge> VE;
VE adj[MAXND];
VI rev[MAXND];

void addedge(int s, edge e)
{
	if(adj[s].size() && adj[s][0].cost > e.cost) 
		adj[s].clear();
	if(adj[s].empty() || adj[s][0].cost == e.cost) 
		adj[s].pb(e);
}

int cost[MAXND], dist[MAXND], able[MAXND];

void ffill(int s)
{
	if(able[s]) return;
	able[s]=1;
	for(VII it=rev[s].begin(); it!=rev[s].end(); ++it)
		ffill(*it);
}

int main()
{
	while(EOF != ni(node_n))
	{
		ni(edge_n);
		ni(sour);
		ni(dest);
		int p, s, t, c1, c2, len;
		for(s=0;s<node_n;s++) 
			adj[s].clear(), rev[s].clear();
		for(p=0;p<edge_n;p++) {
			scanf(" (%d,%d,%d[%d]%d)", &s,&t,&c1,&len,&c2);
			edge e1=(edge){t,c1,len};
			edge e2=(edge){s,c2,len};
			addedge(s,e1);
			addedge(t,e2);
		}
		for(s=0;s<node_n;s++)
		{
			for(VE::iterator it=adj[s].begin(); it!=adj[s].end(); ++it)
				rev[it->next].pb(s);
		}
		fill(able,able+node_n,0);
		ffill(dest);
		
		fill(dist,dist+node_n,INF);
		fill(cost,cost+node_n,INF);
		dist[sour] = 0;
		cost[sour] = 0;
		//prev[sour] = -1;
		int upd;
		for(p=node_n;p>0;p--)
		{
			upd=0;
			for(s=0;s<node_n;s++) if(able[s] && cost[s] != INF)
			for(VE::iterator it=adj[s].begin(); it!=adj[s].end(); ++it) if(able[it->next])
			{
				c1 = cost[s]+it->cost;
				len = dist[s]+it->len;
				t = it->next;
				if(make_pair(c1,len) < make_pair(cost[t], dist[t]))
				{
					cost[t] = c1;
					dist[t] = len;
					//prev[t] = s;
					upd=1;
				}
			}
			//show(dist, dist+node_n);
			if(!upd) break;
		}
		
		if(cost[dest] == INF)
		{
			puts("VOID");
			continue;
		}
		if(upd)
		{
			puts("UNBOUND");
			continue;
		}
		printf("%d %d\n", cost[dest], dist[dest]);
	}
}
