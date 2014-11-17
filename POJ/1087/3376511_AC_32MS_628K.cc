/*
prob:	poj1087
algo:	floyd + max match
author:	liruqi
date:	2008-5-3
*/
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;

string dev[110],plug[110];
bool adj[500][500],vst[110];
int n,m,k;
int match[110];

int dfs(int p){
	int v,t;
	for(v=1;v<=n;v++) if(!vst[v] && adj[p][v]){
		t=match[v];
		vst[v]=1;
		if(t==0 || dfs(t)){
			match[v]=p;
			return 1;
		}
	}
	return 0;
}

int main(){
	map<string,int> rec_id;
	cin>>n;
	int i,j,k,u,v,edge_num;
	string str;
	for(i=1;i<=n;i++){
		cin>>str;
		rec_id[str]=i;
	}
	cin>>m;	
	for(i=1;i<=m;i++){
		cin>>dev[i];
		cin>>plug[i];
	}
	cin>>edge_num;
	int rec_num=n;
	for(i=1;i<=edge_num;i++){
		cin>>str;
		u=rec_id[str];
		if(!u){
			u=(rec_id[str]=++rec_num);
		}
		cin>>str;
		v=rec_id[str];
		if(!v){
			v=(rec_id[str]=++rec_num);
		}
		adj[u][v]=1;
	}
	for(k=1;k<=rec_num;k++)
		adj[k][k]=1;
	for(k=1;k<=rec_num;k++)
		for(u=1;u<=rec_num;u++) if(adj[u][k])
			for(v=1;v<=rec_num;v++) if(adj[k][v])
				adj[u][v]=1;
	int cnt=0;
	for(i=1;i<=m;i++){
		memset(vst,0,sizeof(vst));
		cnt+=dfs(rec_id[plug[i]]);
	}
	cout<<m-cnt<<endl;
}
