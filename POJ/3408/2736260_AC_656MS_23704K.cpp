#include <list>
#include <stdio.h>
using namespace std;
#define maxn 1001
typedef list<int> lit;
list<int> adj[maxn];
list<int> rev[maxn];
int tme[maxn];
int que[maxn];
bool vst[maxn];
bool usl[maxn];
int n, tot, idx;

bool bfs(int s){
    int head = 0;
    int tail = 1;
    memset(vst, 0, maxn*sizeof(bool));
    que[0]=s;
    vst[s]=1;
    tot=-1;
    while(head < tail){
        int st=head;
        int ed=tail;
        tot++;
        for(int i=st; i<ed; i++){
            int u=que[head++];
            for(lit::iterator it=adj[u].begin(); 
                it!=adj[u].end(); ++it)
            {
                int v=*it;
                if(!vst[v]){
                    vst[v]=1;
                    que[tail++]=v;
                }
            }
        }
    }
    if (n==tail) return 1;
    for(int i=1;i<tail;i++)
        usl[que[i]]=1;
    return 0;
}

int main(){
    int p,i,j,v;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p);
        for(j=1;j<=p;j++){
            scanf("%d",&v);
            adj[i].push_back(v);
            rev[v].push_back(i);
        }
    }
    memset(tme, 0xff, maxn*sizeof(tme[0]));
    for(i=1;i<=n;i++)
    {
        if(!usl[i] && bfs(i)){
            tme[i]=tot;
        }
    }
    tot = -1;
    for(i=1;i<=n;i++) if(tme[i]>=0){
        if(tme[i] >= tot)
            idx=i, tot=tme[i];
    }
    if(tot<0) puts("impossible");
    else printf("%d\n%d\n", tot, idx);
    scanf("%d",&n);
	return 0;
}
