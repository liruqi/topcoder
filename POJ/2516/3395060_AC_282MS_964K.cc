/*
  Name: Graph Class
  Copyright: liruqi
  Author: liruqi
  Date: 05-05-08
  Description: a collection for gragh algorithms.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*node size*/
const int node_size=150;
const int inf = 10000;
typedef vector<int> VI;

/*
in this Graph Class, node are labeled from 1
now I have two methods:
	max match		[OK]
	optimal match	[OK]
*/
struct Graph{
	bool adj[node_size][node_size];
	bool v_left[node_size],v_right[node_size];
	int match[node_size];
	int left_num,right_num,node_num;
	int weight[node_size][node_size];
	int l_left[node_size],l_right[node_size];
	void init(){
		memset(adj,0,sizeof(adj));
	}
	
	int max_match_dfs(int p){
		int v,t;
		for(v=1;v<=right_num;v++) if(!v_right[v] && adj[p][v]){
			t=match[v];
			v_right[v]=1;
			if(t==0 || max_match_dfs(t)){
				match[v]=p;
				return 1;
			}
		}
		return 0;
	}
	/*
	maximum match
	precodition: 
		weight[][] have been assigned
	*/
	int max_match(){
		int cnt=0;
		memset(match,0,sizeof(match));
		for(int i=1;i<=left_num;i++){
			memset(v_right,0,sizeof(v_right));
			cnt += max_match_dfs(i);
		}
		return cnt;
	}
	
	int opt_match_dfs(int p){
		int v,t;
		v_left[p]=1;
		for(v=1;v<=right_num;v++)
			if(!v_right[v] && l_left[p]+l_right[v]==weight[p][v]){
				v_right[v]=1;
				t=match[v];
				if(t==0 || opt_match_dfs(t)){
					match[v]=p;
					return 1;
				}
			}
		return 0;
	}
	/*
	optimal match
	???? what if left_num != right_num???
	precodition: 
		weight[][] have been assigned
	*/
	int opt_match(){
		int i,j,k;
		for(i=1;i<=left_num;i++){
			l_left[i]=-inf;
			for(j=1;j<=right_num;j++)
				if(l_left[i]<weight[i][j])
					l_left[i]=weight[i][j];
		}
		memset(l_right,0,sizeof(l_right));
		memset(match,0,sizeof(match));
		for(k=1;k<=left_num;k++){
			while(1){
				memset(v_left, 0,sizeof(v_left ));
				memset(v_right,0,sizeof(v_right));
				if(opt_match_dfs(k)) 
					break;
				int p=inf;
				for(i=1;i<=left_num;i++)
					if(v_left[i])
						for(j=1;j<=right_num;j++)
							if(!v_right[j]){
								int can=(l_left[i]+l_right[j]-weight[i][j]);
								if(p>can)
									p=can;
							}
				for(i=1;i<=left_num;i++)
					if(v_left[i])
						l_left[i]-=p;
				for(j=1;j<=right_num;j++)
					if(v_right[j])
						l_right[j]+=p;
			}
		}
		int ret=0;
		for(k=1;k<=right_num;k++)
			ret+=weight[match[k]][k];
		return ret;
	}
};

int order[50][50],supply[50][50],N,M,K,cost[50][50][50];
int left_id[150],right_id[150];
Graph g;
int slv(){
	int i,k,lt,rt,ret=0;
	for(k=1;k<=K;k++){
		g.init();
		g.left_num=0;
		g.right_num=0;
		for(i=1;i<=N;i++){
			while(order[k][i]){
				order[k][i]--;
				g.left_num++;
				left_id[g.left_num]=i;
			}
		}
		for(i=1;i<=M;i++){
			while(supply[k][i]){
				supply[k][i]--;
				g.right_num++;
				right_id[g.right_num]=i;
			}
		}
		if(g.left_num>g.right_num)
			return -1;
		
		for(lt=1;lt<=g.left_num;lt++)
			for(rt=1;rt<=g.right_num;rt++)
				g.weight[lt][rt] = -cost[k][left_id[lt]][right_id[rt]];
		for(   ;lt<=g.right_num;lt++)
			for(rt=1;rt<=g.right_num;rt++)
				g.weight[lt][rt] = -inf;
		int d = g.right_num-g.left_num;
		g.left_num = g.right_num;
		int res=-g.opt_match() - d*inf;
		//cout<<k<<" -> "<<res<<endl;
		ret+=res;
	}
	return ret;
}

int main(){
	int i,j,k,t;
	while(1){
		scanf("%d",&N);
		scanf("%d",&M);
		scanf("%d",&K);
		if(!N) break;
		
		for(i=1;i<=N;i++)
			for(k=1;k<=K;k++)
				scanf("%d",&order[k][i]);
		for(i=1;i<=M;i++)
			for(k=1;k<=K;k++)
				scanf("%d",&supply[k][i]);
		for(k=1;k<=K;k++)
		for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			scanf("%d",&cost[k][i][j]);
		printf("%d\n",slv());
	}
	return 0;
}
