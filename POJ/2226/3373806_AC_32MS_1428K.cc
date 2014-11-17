/*
prob:	poj3041
algo:	max match = min cut
author:	liruqi
time:	16:23 2008-5-2
*/
#include<stdio.h>
#include<string.h>

char grid[51][51],adj[2500][2500],vst[2500];
int rid[51][51],cid[51][51],match[2500];

int row,col,r_num,c_num;

int dfs(int p){
	for(int c=1;c<=c_num;c++) if(!vst[c]&&adj[p][c]){
		vst[c]=1;
		if(match[c]==-1 || dfs(match[c])){
			match[c]=p;
			return 1;
		}
	}
	return 0;
}

int slv(){
	int cnt=0,i;
	memset(match,-1,sizeof(match));
	for(i=1;i<=r_num;i++){
		memset(vst,0,sizeof(vst));
		cnt+=dfs(i);
	}
	return cnt;
}

int main(){
	int r,c,k;
	scanf("%d",&row);
	scanf("%d",&col);
	
	for(r=0;r<row;r++)
		scanf("%s",grid[r]);
	k=1;
	//row id assign
	for(r=0;r<row;r++)
		for(c=0;c<col;c++) if(grid[r][c]=='*'){
			if(c==0 || grid[r][c-1]!='*')
				k++;
			rid[r][c]=k;
		}
	r_num=k;
	k=1;
	//column id assign
	for(c=0;c<col;c++) 
		for(r=0;r<row;r++) if(grid[r][c]=='*'){
			if(r==0 || grid[r-1][c]!='*')
				k++;
			cid[r][c]=k;
		}
	c_num=k;
	for(r=0;r<row;r++)
		for(c=0;c<col;c++) if(grid[r][c]=='*'){
			adj[ rid[r][c] ][ cid[r][c] ]=1;
		}
	printf("%d\n",slv());
}
