#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


const int n_size = 410;
//the max possible flow
const int inf    = 0x0f0f0f0f;

struct FlowGraph{
    
    typedef vector<int> VI;
    typedef VI::iterator VII;
    int flow[n_size][n_size];
    int capct[n_size][n_size];
    VI adj[n_size];
    int visit[n_size];
    
    int n_node,sour,dest;
    
    void init(){
        memset(capct,0,sizeof(capct));
        for(int u=1;u<n_size;u++)
            adj[u].clear();
    }
    int aug_path(int s, int f){
        //cout<<s<<" "<<f<<endl;
        visit[s]=1;
        if(s==dest)
            return f;
        for(int t=1;t<=n_node;t++){
            int rc=capct[s][t]-flow[s][t];
            if(!visit[t] && rc>0)
            {
                int fi=min(f,rc);
                int ret=aug_path(t,fi);
                if(ret > 0){
                    flow[s][t]+=ret;
                    flow[t][s]=-flow[s][t];
                    return ret;
                }
            }
        }
        return 0;
    }
    /*
    FordFulkson method
    return the max flow
    */
    int FordFulkson(){
        memset(flow,0,sizeof(flow));
        int ret=0,add;
        do{
            memset(visit,0,sizeof(visit));
            add=aug_path(sour,inf);
            ret+=add;
            //cout<<add<<endl;
        }while(add);
        return ret;
    }
};

FlowGraph g;
int main(){
    int edge,s,t,i,w;
    
    while(cin>>edge){;
    cin>>g.n_node;
    g.init();
    g.sour=1;
    g.dest=g.n_node;
    
    for(i=1;i<=edge;i++){
		cin>>s>>t;
		cin>>w;g.capct[s][t]+=w;
		g.adj[s].push_back(t);
	}
    cout<<g.FordFulkson()
        <<endl;
	}
    
}