//poj2536
//max match

#include<iostream>
using namespace std;
const int maxn = 100;
int n,m,s,v;
struct point{
	double x,y;
} G[maxn], H[maxn];
bool adj[maxn][maxn];
bool vst[maxn];
int  match[maxn];
double limit;

bool reachable(struct point a,struct point b){
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	double ds=dx*dx+dy*dy;
	return ds<=limit;
}

void init(){
	int i,j;
	memset(adj,0,sizeof(adj));
	for(i=1;i<=n;i++)
		cin>>G[i].x>>G[i].y;
	for(i=1;i<=m;i++)
		cin>>H[i].x>>H[i].y;
	limit=s*s*v*v;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(reachable(G[i],H[j]))
				adj[i][j]=1;
}

bool dfs(int p){
	int i,t;
	for(i=1;i<=m;i++)if(adj[p][i]&&!vst[i]){
		vst[i]=1;
		t=match[i];
		match[i]=p;
		if(t<0 || dfs(t))
			return 1;
		match[i]=t;
	}
	return 0;
}

void solve(){
	int cnt=0;
	int i;
	memset(match,0xff,maxn*4);
	for(i=1;i<=n;i++){
		memset(vst,0,maxn);
		if(dfs(i))
			cnt++;
	}
	cout<<(n-cnt)<<endl;
}

int main()
{
	while(cin>>n>>m>>s>>v){
		init();
		solve();
	}
	return 0;
} 
