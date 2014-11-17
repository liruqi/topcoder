#include <iostream>
#include <list>
#include <cstring>
using namespace std;
#define maxb 600
char bead[maxb+1][11];
list <int> B[maxb+1];
typedef list <int>::iterator lii;
long long dp[maxb+1][101];
int n, l, m;

bool adjacent(int u, int v){
    int i=1;
    int j=0;
    for(;bead[u][i]!='\0';i++,j++)
    if(bead[u][i]!=bead[v][j])
    return 0;
    return 1;
}
void
prtgra(){
    int i;
    for(i=1;i<=m;i++){
        cout<<i<<" -> ";
        for(lii iter=(B[i]).begin(); iter!=(B[i]).end(); ++iter)
        cout<<(*iter)<<" ";cout<<endl;
    }
}

void
buildG(){
    int i,j;
    for(i=1;i<=m;i++)B[i].clear();
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            if(adjacent(i,j))
                B[i].push_back(j);
    //prtgra();
}

void
solve(){
    int i,j;
    memset(dp, 0, 8*101*(maxb+1));
    for(i=1;i<=m;i++)
        dp[i][1]=1;
    int p=l-strlen(bead[1])+1;
    for(i=2;i<=p;i++)
        for(j=1;j<=m;j++)
            for(lii iter=B[j].begin(); iter!=B[j].end(); ++iter)
            dp[j][i]+=dp[*iter][i-1];
    long long cnt=0;
    for(j=1;j<=m;j++)
        cnt+=dp[j][p];
    cout<<cnt<<endl;
}
int main(){
    
    cin>>n>>l>>m;
    while(n||l||m){
        for(int i=1;i<=m;i++)
            cin>>bead[i];
        buildG();
        solve();
        cin>>n>>l>>m;
    }
}
