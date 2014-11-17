#include <list>
#include <iostream>
using namespace std;
#define MAXN 10000
typedef list<int>::iterator lii;
list <int> adj[MAXN];
int N;
bool color[MAXN];

int solve(){
	int i,cnt=0;
	memset(color, 0, MAXN);
	for(i=1;i<=N;i++) if(!color[i])
		if(adj[i].size()==1){
			color[(*adj[i].begin())]=1; 
		}
	for(i=1;i<=N;i++) if(color[i]){
		//cout<<i<<" ";
		cnt++;
		while(adj[i].size()>0){
			int j=*adj[i].begin();
			adj[i].remove(j);
			adj[j].remove(i);
		}
	}
	if(cnt)
		return cnt+solve();
	return 0;
}

int main(){
	int i,u,v;
	while(1){
		cin>>N;
		for(i=1;i<=N;i++)
			adj[i].clear();
		for(i=1;i<N;i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout<<solve()<<endl;
		cin>>N;
		if(N<0) return 0;
	}
}