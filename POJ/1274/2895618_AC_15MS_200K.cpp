/*

poj 1274

*/



#include <iostream>

using namespace std;

#define maxn 250

bool visit[maxn];

bool adj[maxn][maxn];

int match[maxn],m,n;



bool DFS(int p){

    int i, t;

    for(i = 1; i <= m; i++) {

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

    cout<<save<<endl;

}



int main(){

    int u,v,i,j,k;
    while(cin>>n>>m){

    memset(match,0xff,sizeof(match));

    memset(adj,0,sizeof(adj));

    for(i=1;i<=n;i++){

        cin>>k;

        for(j=0;j<k;j++) {
        	cin>>v;
        	adj[i][v]=true;
        }

    }

    solve();
    }

    return 0;

} 
