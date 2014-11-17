
#include<algorithm>
#include<stdio.h>
#include<set>

using namespace std;
struct wall{
	int row,clt,crt;
};
wall W[101];
struct cmp{
	bool operator()(int p,int q){
		if(W[p].crt!=W[q].crt)
			return W[p].crt<W[q].crt;
		return W[p].row<W[q].row;
	}
};
set<int,cmp> adj[101];

int n,k;
int slv(){
	int i,j;
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=0;i<=100;i++)
		adj[i].clear();
	for(i=0;i<n;i++){
		scanf("%d",&W[i].clt);
		scanf("%d",&W[i].row);
		scanf("%d",&W[i].crt);
		scanf("%d",&W[i].row);
		if(W[i].crt<W[i].clt) swap(W[i].clt,W[i].crt);
		for(j=W[i].clt;j<=W[i].crt;j++)
			adj[j].insert(i);
	}
	int ret=0;
	for(i=0;i<=100;i++){
		while(adj[i].size()>k){
			int rmv=*--adj[i].end();
			for(j=i;j<=W[rmv].crt;j++)
				adj[j].erase(rmv);
			ret++;
		}
	}
	return ret;
}

int main(){
	int ks;
	scanf("%d",&ks);
	while(ks--){
		printf("%d\n",slv());
	}
}
