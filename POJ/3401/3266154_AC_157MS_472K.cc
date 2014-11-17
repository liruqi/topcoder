#include <iostream>
using namespace std;
#define maxl (1<<8)
char dp[maxl][maxl], str[maxl];
int len[maxl];

int main()
{
    int i,j,sl,sub,b1,b2;
    cin>>str;
    sl = strlen(str);
    for(i=0;i<sl;i++) dp[i][i]=str[i];
    for(sub=2;sub<sl;sub++)
        for(i=0;i+sub<sl;i++){
            j=i+sub;
            for(b1=i+1;b1<j;b1++)if(dp[i][b1-1]){
                for(b2=b1;b2<j;b2++)
                    if(dp[b2+1][j]==dp[i][b1-1]&&dp[b1][b2]){
                        dp[i][j]=dp[b1][b2];
                        break;
                    } if(dp[i][j])break; }
        }
    for(i=0;i<sl;i++)
        len[i]=dp[0][i]?1:maxl;
    for(i=1;i<sl;i++)
        for(j=i;j<sl;j++)if(dp[i][j])
            len[j]<?=len[i-1]+1;
    cout<<len[sl-1]<<endl;
    return 0;
}
