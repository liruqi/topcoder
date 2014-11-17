#include <stdio.h>
#include <list>
using namespace std;
#define MAXV 1001
typedef list<int> lit;
typedef lit::iterator lii;
lit adj[MAXV];
int weight[MAXV][MAXV], E, N, d[MAXV];
bool used[MAXV];

int main(){
    int i,j,u,v,w;
    scanf("%d%d",&E,&N);
    memset(weight,0x1f,MAXV*MAXV*4);
    memset(d, 0x1f, MAXV*4);
    memset(used, 0, MAXV);
    for(i=1;i<=E;i++){
        scanf("%d%d%d",&u,&v,&w);
        if(w<weight[u][v]){
            adj[u].push_back(v);
            adj[v].push_back(u);
            weight[u][v]=w;
            weight[v][u]=w;
        } 
    }
    d[1]=0; used[1]=1;
	for(lii it=adj[1].begin(); it!=adj[1].end(); ++it) d[*it]=weight[1][*it];
    while(1){
    	for(u=0,i=1;i<=N;i++)if(!used[i] && d[i]<d[u]) u=i;
    	if(u==0) break;
    	used[u]=1;
    	for(lii it=adj[u].begin(); it!=adj[u].end(); ++it) if(!used[*it]){
    		v = *it;
    		d[v] <?= d[u]+weight[u][v];
    	}
    }
    printf("%d\n",d[N]);
}