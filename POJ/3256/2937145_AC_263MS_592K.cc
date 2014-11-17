#include <iostream>
#include <list>
using namespace std;

const int maxn = 1001;
int K,M,N;
int grz[maxn];
bool rba[maxn];
bool vst[maxn];
typedef list<int> lit;
typedef lit::iterator lii;
lit adj[maxn];

void dfs(int u){
	vst[u]=true;
	for(lii it=adj[u].begin(); it!=adj[u].end(); ++it)
		if(!vst[*it])
			dfs(*it);
}

int main(){
	int u,v,c=0;
	cin>>K>>N>>M;
	for(int i=0;i<K;i++)
		cin>>grz[i];
	for(int i=0;i<M;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	memset(rba,true,sizeof(rba));
	for(int i=0;i<K;i++) {
		memset(vst,0,sizeof(vst));
		dfs(grz[i]);
		for(int j=1;j<=N;j++)
			rba[j]=rba[j]&&vst[j];
	}
	for(int i=1;i<=N;i++) if(rba[i]) c++;
	cout<<c<<endl;
}
