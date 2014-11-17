#include <iostream>

using namespace std;

#define maxn 100

bool check[maxn];

bool adj[maxn][maxn];

int match[maxn],m,n;



bool DFS(int p)

{

    int i, t;

    for(i = 0; i < m; i++) {

        if(adj[p][i] && !check[i]) {

            check[i] = true;

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

    for(i = 0; i < n; i++) {

        memset(check, false, sizeof(check));

        if(DFS(i)) {

            save++;

        }

    }

    cout<<save<<endl;

}



int main(){

    int u,v,i,j,k;

    while(cin>>n && n){
    	cin>>m>>k;
    	memset(match,0xff,sizeof(match));
    	memset(adj,0,sizeof(adj));

        for(i=k;i;i--){

            cin>>j>>u>>v;

            if(u&&v) adj[u][v]=true;

        }

        solve();

    }

} 
