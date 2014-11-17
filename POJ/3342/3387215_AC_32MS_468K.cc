/*
algo: tree dp
author: liruqi
date: 2006-5-4
*/
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string,int> id;
vector<int> adj[210];
struct node{
	int ft,sd;
	bool u_ft,u_sd;
}stt[210];

int top,n;

int getid(string str){
	int ret=id[str];
	if(!ret){
		ret = (id[str] = ++top);
	}
	return ret;
}

void dfs(int u){
	int dgr=adj[u].size();
	stt[u].ft=0;
	stt[u].sd=1;
	stt[u].u_ft=1;
	stt[u].u_sd=1;
	for(int i=0;i<dgr;i++){
		int v=adj[u][i];
		dfs(v);
		if(stt[v].ft > stt[v].sd){
			stt[u].ft+=stt[v].ft;
			if(!stt[v].u_ft)
				stt[u].u_ft=0;
		} else if(stt[v].ft < stt[v].sd){
			stt[u].ft+=stt[v].sd;
			if(!stt[v].u_sd)
				stt[u].u_ft=0;
		} else {
			stt[u].ft+=stt[v].ft;
			stt[u].u_ft=0;
		}
		stt[u].sd+=stt[v].ft;
		if(!stt[v].u_ft)
			stt[u].u_sd=0;
	}
}

int main(){
	while(1){
		cin>>n;
		if(!n) break;
		string chd,dad;
		
		id.clear();
		top=0;
		for(int i=0;i<210;i++)
			adj[i].clear();
		cin>>dad;
		id[dad]=++top;
		for(int i=1;i<n;i++){
			cin>>chd;
			cin>>dad;
			int u=getid(chd);
			int v=getid(dad);
			adj[v].push_back(u);
		}
		adj[0].push_back(1);
		dfs(0);
		cout<<stt[0].ft
			<<(stt[0].u_ft?" Yes":" No")
			<<endl;
	}
	return 0;
}