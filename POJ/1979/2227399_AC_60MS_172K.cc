#include <iostream>
using namespace std;

bool A[21][21];
int W, H, C;
char G[21][21];

bool valid(int r, int c){
    if(r>0 && r<=H)
        if(c>0 && c<=W)
            if(G[r][c]=='.')
            return 1;
            return 0;
}

void bfs(int r, int c){
    C++;
    A[r][c]=0;
    if(valid(r+1,c) && A[r+1][c]) bfs(r+1, c);
    if(valid(r-1,c) && A[r-1][c]) bfs(r-1, c);
    if(valid(r,c+1) && A[r][c+1]) bfs(r, c+1);
    if(valid(r,c-1) && A[r][c-1]) bfs(r, c-1);
}

int main()
{
	int i, j;
	int sr=1, sc=1;
    while(cin>>W>>H && W){
        C=0;
    	for(i=1; i<=H; i++)for(j=1; j<=W; j++){
    	    cin>>G[i][j];
    	    A[i][j]=1;
    	    if(G[i][j]=='@') 
            {sr=i; sc=j;}
    	}
    	
    	A[sr][sc]=0;
    	bfs(sr, sc);
    	cout<<C<<endl;
    }
	return 0;
}
