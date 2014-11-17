#include<algorithm>
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string,int> id;
int father[210];
struct node{
	int ft,sd;
	bool u_ft,u_sd;
}stt[210];

int top,n;

int getid(string str){
	if(id.find(str)==id.end()){
		top++;
		id[str]=top; 
		return top;
	}
	return id[str];
}

void dfs(int u){
	stt[u]=(node){0,1,1,1};
	for(int v=1;v<=n;v++)if(father[v]==u){
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
		memset(father,-1,sizeof(-1));
		cin>>dad;
		father[getid(dad)]=0;
		for(int i=1;i<n;i++){
			cin>>chd;
			cin>>dad;
			int u=getid(chd);
			int v=getid(dad);
			father[u]=v;
		}
		
		dfs(0);
		cout<<stt[0].ft
			<<(stt[0].u_ft?" Yes\n":" No\n");
	}
	return 0;
}

