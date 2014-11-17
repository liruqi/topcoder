#include<map>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

int n;
map<string, int> id;
bool adj[30][30];
double dist[30][30];
/*
struct node{
	int u,v;
	double w;
}edge[900];
*/
int main(){
	int ks=1;
	while(cin>>n, n) {
		string u,v;
		int i,j,k;
		double cur;
		id.clear();
		memset(adj,0,sizeof(adj));
		memset(dist,0,sizeof(dist));
		for(i=0;i<n;i++) {
			cin>>u;
			id[u] = i;
		}
		cin>>k;
		while(k--) {
			cin>>u>>cur>>v;
			i=id[u];
			j=id[v];
			adj[i][j]=1;
			dist[i][j]=cur;
		}
		bool fd=0;
		for(k=0;k<n;k++)
			for(i=0;i<n;i++) if(adj[i][k])
				for(j=0;j<n;j++) if(adj[k][j])
				{
					double can = dist[i][k]*dist[k][j];
					if(adj[i][j]) dist[i][j] >?= can;
					else {
						adj[i][j]=1;
						dist[i][j] = can;
					}
				}

		for(i=0;i<n;i++){
			if(dist[i][i]>1) break;
		}
		cout<<"Case "<<ks++<<": "<<(i==n?"No":"Yes")<<endl;
	}
}