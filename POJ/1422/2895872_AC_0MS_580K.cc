/*

poj 2594

*/



#include <iostream>

using namespace std;

#define maxn 510

bool visit[maxn];

bool adj[maxn][maxn];

int match[maxn],m,n;



bool DFS(int p){

    int i, t;

    for(i = 1; i <= n; i++) {

        if(adj[p][i] && !visit[i]) {

            visit[i] = true;

            t = match[i];

            match[i] = p;

            if(t == -1 || DFS(t)) {

                return true;

            }

            match[i] = t;

        }

    }

    return false;

}



void solve(){

    int i,save = 0;

    for(i = 1; i <= n; i++) {

        memset(visit, false, sizeof(visit));

        if(DFS(i)) {

            save++;

        }

    }

    cout<<(n-save)<<endl;

}



int main(){

    int u,v,i,j,k;cin>>n;
    while(cin>>n>>m && n){

    	memset(match,0xff,sizeof(match));

    	memset(adj,0,sizeof(adj));

	    for(i=1;i<=m;i++){
        	cin>>u>>v;
	       	adj[u][v]=true;

	    }

	    solve();
    }

    return 0;

}

