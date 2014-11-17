#include <stdio.h>
#include <queue>
#include <list>
using namespace std;
#define MAXV 1001
typedef list<int> lit;
typedef lit::iterator lii;
list<int> adj[MAXV];
int weight[MAXV][MAXV], E, N, d[MAXV];
bool used[MAXV];
struct cmp{
	bool operator()(int x, int y)
	{
		return d[x]>d[y];
	}
};

int main(){
    int i,u,v,w;
    scanf("%d%d",&E,&N);//cin>>E>>N;
    memset(weight,0x1f,MAXV*MAXV*4);
    memset(d, 0x1f, MAXV*4);
    memset(used, 0, MAXV);
    
    priority_queue <int,vector<int>, cmp> pq;
    for(i=1;i<=N;i++) 
        adj[i].clear();
    for(i=1;i<=E;i++){
        //cin>>u>>v>>w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        weight[u][v]<?=w;
        weight[v][u]<?=w;
    }
    //Dijkstra
    d[1]=0; 
    pq.push(1);
    for(; !pq.empty(); ){
        int u=pq.top();pq.pop();if(!used[u]){
        used[u]=1;
        for(lii it=adj[u].begin(); it!=adj[u].end(); ++it) if(!used[*it]){
            v = *it;
            d[v] <?= d[u]+weight[u][v];
            pq.push(v);
        }}
    }
    printf("%d\n",d[N]);
}