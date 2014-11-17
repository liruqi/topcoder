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
const int node_size=110;
const int inf = 0x0f0f0f0f;
typedef vector<int> VI;

/*
in this Graph Class, node are labeled from 1
now I have two methods:
	max match
	optimal match
both have not been tested yet
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
		memset(l_right,1,sizeof(l_right));
		memset(match,0,sizeof(match));
		for(k=1;k<=left_num;k++){
			while(1){
				memset(v_left, 0,sizeof(v_left ));
				memset(v_right,0,sizeof(v_right));
				if(opt_match_dfs(k)) break;
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
/*
先将一个未被匹配的顶点u(u in {x})做一次增广路，记下哪些结点被访问那些结点没有被访问。
求出d=min{lx[i]+ly[j]-w[i,j]}其中i结点被访问，j结点没有被访问。
然后调整lx和ly：对于访问过的x顶点，将它的可行标减去d，对于所有访问过的y顶点，将它的可行标增加d。
修改后的顶标仍是可行顶标，原来的匹配M仍然存在，相等子图中至少出现了一条不属于M的边，所以造成M的逐渐增广。
Kuhn－Munkras算法流程：
(1)初始化可行顶标的值
(2)用匈牙利算法寻找完备匹配
(3)若未找到完备匹配则修改可行顶标的值
(4)重复(2)(3)直到找到相等子图的完备匹配为止
*/


int main(){
	int man[node_size][2],home[node_size][2];
	while(1){
	Graph g;
	char grid[210][210];
	int row,col,ln=0,rn=0;
	cin>>row;
	cin>>col;
	if(!row)break;
	for(int r=0;r<row;r++){
		cin>>grid[r];
		for(int c=0;c<col;c++){
			if(grid[r][c]=='m'){
				++ln;
				man[ln][0]=r;
				man[ln][1]=c;
			} else if(grid[r][c]=='H'){
				++rn;
				home[rn][0]=r;
				home[rn][1]=c;
			}
		}
	}
	for(int l=1;l<=ln;l++)
	for(int r=1;r<=rn;r++)
		g.weight[l][r]=(-abs(man[l][0]-home[r][0])-abs(man[l][1]-home[r][1]));
	g.left_num=ln;
	g.right_num=rn;
	cout<<(-g.opt_match())<<endl;
	}
	return 0;
}
/*
2 2
mH
Hm
*/
