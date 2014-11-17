#include <iostream>
#include <algorithm>
#define maxn 1100
#define maxp 15
using namespace std;


int w[maxn],b[maxn],dp[maxn][maxp+1][maxp+1];
int main()
{
    int k,j,i=1, N;
    while(cin>>w[i]>>b[i]) i++;
    N=i-1;
    for(k=1;k<=N;k++){
        for(i=0;i<=maxp&&i<=k;i++){
            if(i==0){
                for(j=1;j<=maxp&&j<=k;j++)
                dp[k][0][j]=max(dp[k-1][0][j], dp[k-1][0][j-1]+b[k]);
            }
            else {
                dp[k][i][0]=max(dp[k-1][i][0], dp[k-1][i-1][0]+w[k]);
                for(j=1;j<=maxp&&j<=k;j++)
                dp[k][i][j]=max(dp[k-1][i][j], max(dp[k-1][i-1][j]+w[k], dp[k-1][i][j-1]+b[k]));
            }
        }
    }
    cout<<dp[N][maxp][maxp]<<endl;
    //system("pause");
    return 0;
}
