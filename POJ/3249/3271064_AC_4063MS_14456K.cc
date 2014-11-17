#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> VI;
#define mx 100001

VI adj[mx];
int prf[mx], idgr[mx], odgr[mx], dp[mx];
int n,m;
char vst[mx];
int stk[mx],top;

void dfs(int u){
    int i;
    VI &cur=adj[u];
    vst[u]=1;
    for(i=0;i<odgr[u];i++)
        if(!vst[cur[i]])
            dfs(cur[i]);
    stk[top++]=u;
}

void solve(){
    int i,j,u,v;
    memset(idgr,0,sizeof(idgr));
    memset(odgr,0,sizeof(odgr));
    for(i=1;i<=n;i++) 
        scanf("%d", prf+i), adj[i].clear();
    for(i=1;i<=m;i++) {
        scanf("%d", &u);
        scanf("%d", &v);
        adj[u].push_back(v);
        odgr[u]++;
        idgr[v]++;
    }
    memset(dp, 0x80, sizeof(dp));
    memset(vst,0, sizeof(vst));
    top=0;
    for(i=1;i<=n;i++)
        if(idgr[i]==0)
            dp[i]=0, dfs(i);
    reverse(stk,stk+top);
    for(i=0;i<top;i++){
        u=stk[i];
        v=dp[u]+prf[u];
        for(j=0;j<odgr[u];j++)
            if(v>dp[adj[u][j]])
                dp[adj[u][j]] = v;
    }
    int res=dp[0];
    for(i=1;i<=n;i++)
        if(odgr[i]==0)
            res >?= dp[i]+prf[i];
    printf("%d\n", res);
}

int main(){
    while(scanf("%d%d",&n,&m)!=-1) solve();
}
