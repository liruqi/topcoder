#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
const int maxn = 110;
double adj[maxn][maxn];
double pro[maxn];
bool vst[maxn];
int n,m;

typedef struct _node{
	double p;
	int u;
}node;


struct cmp{
	bool operator()(node p,node q){
		return p.p<q.p;
	}
};

void dij(){
	priority_queue<node, vector<node>, cmp> pq;
	memset(vst,0,sizeof(vst));
	int i;
	for(i=1;i<=n;i++)
		pro[i]=0;
	node nd={100.0,1},nn;
	pq.push(nd);
	pro[1]=100.0;
	while(!pq.empty()){
		nd = pq.top();
		pq.pop();
		if(vst[nd.u])continue;
		vst[nd.u]=1;
		for(i=1;i<=n;i++)if(!vst[i] && adj[nd.u][i]>0){
			double nv=nd.p*adj[nd.u][i];
			if(nv>pro[i]){
				pro[i]=nv;
				nn.u=i,nn.p=nv;
				pq.push(nn);
			}
		}
	}
printf("%.6lf percent\n",pro[n]);
}

int main(){
	int i,u,v,w;
	double p;
	while( cin>>n && n>0){
		for(u=1;u<=n;u++)
			for(v=1;v<=n;v++)
				adj[u][v]=-1;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>u>>v>>w;
			p=(double)w/100.0;
			adj[u][v] = p;
			adj[v][u] = p;
		}
		dij();
	}
}