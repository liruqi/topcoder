#include <iostream>
#include <list>
using namespace std;

typedef list<int> lit;
typedef lit::iterator lii;
#define maxn 1000
lit Adj[maxn+1];
bool vst[maxn+1];
int N;
int Qu[maxn+1], head, tail;

void enqu(int u){
    Qu[tail++]=u;
    vst[u]=1;
}
int dequ(){return Qu[head++];}

bool bfs(int sour, int dest){
    memset(vst+1, 0, maxn);
    head=tail=0;
    enqu(sour);
    while(head<tail){
        int st=dequ();
        for(lii it=Adj[st].begin(); it!=Adj[st].end(); ++it)
            if(!vst[*it])
                enqu(*it);
        if(vst[dest]) return 1;
    }
    return 0;
}

int main(){
    int Q,u,v;
    char cmd[3];
    cin>>N>>Q;
    while(Q--){
        lii it;
        cin>>cmd>>u>>v;
        switch (cmd[0]){
            case 'I':
                Adj[u].push_back(v);
                Adj[v].push_back(u);
                break;
            case 'D':
                it=find(Adj[u].begin(), Adj[u].end(), v);
                Adj[u].erase(it);
                it=find(Adj[v].begin(), Adj[v].end(), u);
                Adj[v].erase(it);
                break;
            case 'Q':
                puts(bfs(u,v)?"Y":"N");
                break;
        }
    }
    return 0;
}
