#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


const int n_size = 410;
//the max possible flow
const int inf    = 1;

struct FlowGraph{
    

    int flow[n_size][n_size];
    int capct[n_size][n_size];

    int visit[n_size];
    
    int n_node,sour,dest;
    
    void init(){
        memset(capct,0,sizeof(capct));
    }
    int aug_path(int s, int f){
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

    int F,N,D,s,t,i,fi,di;
    cin>>N;
    cin>>F;
    cin>>D;
    g.init();
    g.n_node=F+2*N+D+2;
    g.sour=F+2*N+D+1;
    g.dest=F+2*N+D+2;
    
    for(s=F+1;s<=F+N;s++){
        t=s+N;
        g.capct[s][t]=1;
    }
    for(s=1;s<=F;s++)
        g.capct[g.sour][s]=1;
    for(s=1;s<=D;s++)
        g.capct[s+F+2*N][g.dest]=1;
    
    for(s=1;s<=N;s++){
        cin>>fi;
        cin>>di;
        for(i=0;i<fi;i++){
            cin>>t;
            g.capct[t][F+s]=1;
        }
        for(i=0;i<di;i++){
            cin>>t;
            g.capct[s+F+N][t+2*N+F]=1;
        }
    }
    
    cout<<g.FordFulkson()
        <<endl;
    
}
