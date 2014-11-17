#include <stdio.h>
#include <string.h>
#include <list>
#define maxn 11
#define inf 0x1f1f1f1f
using namespace std;

int dp[1<<maxn][maxn];

struct edge{
	int cb,cc,cp,cr;
};

list<edge> G[maxn];
int N,m;

void dfs(int st, int tc, int cost){
	int cb,cc,cp,cr;
	if(dp[st][tc]<=cost)
		return;
	dp[st][tc]=cost;
	for(list<edge>::iterator it=G[tc].begin();
		it!=G[tc].end();  ++it)
		{
			cb=it->cb;
			cc=it->cc;
			cp=it->cp;
			cr=it->cr;
			if(st & (1<<cc))
				dfs(st|(1<<cb), cb, cp+cost);
			else 
				dfs(st|(1<<cb), cb, cr+cost);
		}
}

int main(){
	int i,a,b,c,p,r;
	memset(dp,0x1f,sizeof(dp));
	scanf("%d%d",&N,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
		edge *ep = new edge;
		ep->cb=b-1;
		ep->cc=c-1;
		ep->cp=p;
		ep->cr=r;
		G[a-1].push_back(*ep);
	}//a,b,c为节点ID,各减一

	dfs(1,0,0);
	
	a=inf;
	for(i=0;i<(1<<N);i++)
		if(a>dp[i][N-1])
			a=dp[i][N-1];
	if(a==inf) puts("impossible");
	else printf("%d\n",a);
	return 0;
}