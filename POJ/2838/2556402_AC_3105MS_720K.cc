#include <iostream>
#include <list>
using namespace std;
typedef list<int> lit;
typedef lit::iterator lii;
#define maxn 1000
lit Adj[maxn+1];
bool vst[maxn+1],found;
int N, dest,Q,u,v;
void dfs(int sour){
    vst[sour]=1;
    if(found) return;
    if(sour==v) found=1;
    for(lii it=Adj[sour].begin(); it!=Adj[sour].end(); ++it)
        if(!vst[*it])
            dfs(*it);
}
int main(){
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
                memset(vst+1, 0, maxn);
                found=0;dfs(u);
                puts(found?"Y":"N");
                break;
        }
    }
    return 0;
}
