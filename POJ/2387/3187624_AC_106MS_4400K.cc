//Dijkstra + heap



#include <iostream>

#include <queue>

#include <list>

using namespace std;

#define MAXV 1001

typedef list<int> lit;

typedef lit::iterator lii;

list<int> adj[MAXV];

int weight[MAXV][MAXV], E, N, d[MAXV];

bool used[MAXV];
struct node{
	int u,w;
};

struct cmp{

	bool operator()(node x, node y){return x.w>y.w;}

};



int main(){

    int i,u,v,w;

    cin>>E>>N;

    memset(weight,0x1f,MAXV*MAXV*4);

    memset(d, 0x1f, MAXV*4);

    memset(used, 0, MAXV);

    

    

    for(i=1;i<=N;i++) 

        adj[i].clear();

    for(i=1;i<=E;i++){

        cin>>u>>v>>w;

        adj[u].push_back(v);

        adj[v].push_back(u);

        weight[u][v]<?=w;

        weight[v][u]<?=w;

    }

    //Dijkstra

    d[1]=0;
    priority_queue <node,vector<node>, cmp> pq;

    pq.push((node){1,0});

    while(pq.size()){

        node nd=pq.top();pq.pop();
        u=nd.u;

        if(!used[u]){

            used[u]=1;

            for(lii it=adj[u].begin(); it!=adj[u].end(); ++it){

                v = *it;
                w = nd.w+weight[u][v];
                if(d[v]>w){

                	d[v] = w;

                	pq.push((node){v,w});
                }

            }

        }

    }

    cout<<d[N]<<endl;

}
