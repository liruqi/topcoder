#include <stdio.h>
#include <string.h>
#define maxn 100010
char st[maxn], ed[maxn];
char buf[1010];
int N;
int dd[30]; //degree difference

bool Adj[30][30];
bool exi[30],vst[30];

void dfs(int p){
    int i;
    for(i=0;i<26;i++)if(Adj[p][i]&&!vst[i]) {
        vst[i]=1;
        dfs(i);
    }
}

bool connected(int sn){
    int i;
    memset(vst,0,30);
    vst[sn]=1;
    dfs(sn);
    for(i=0;i<26;i++)
        if(exi[i])
            if(!vst[i])
                return 0;
    return 1;
}
bool eulerPath(){
    bool spf=0,epf=0;
    int i;
    for(i=0;i<26;i++)if(dd[i])
    {
        if(dd[i]==-1){
            if(spf) return 0;
            else {
                spf=1;
            }
        }
        else if(dd[i]==1){
            if(epf) return 0;
            else {
                epf=1;
            }
        }
        else return 0;
    }
    
    for(i=0;i<26;i++)
        if(exi[i] && connected(i))
            return 1;
    return 0;
}

int main(){
    int T,i,u,v;
    scanf("%d\n",&T);
    while(T--){
        memset(dd, 0, 120);
        memset(exi,0,30);
        
        memset(Adj,0,30*30);
        scanf("%d\n",&N);
        for(i=1;i<=N;i++){
            scanf("%s",buf);
            st[i]=buf[0]; ed[i]=buf[strlen(buf)-1];
            u=st[i]-'a';
            v=ed[i]-'a';
            dd[u]++;
            dd[v]--;
            exi[u]=1;
            exi[v]=1;
            Adj[u][v]=1;
        }
        puts(eulerPath()?"Ordering is possible.":"The door cannot be opened.");
    }
    return 0;
}
