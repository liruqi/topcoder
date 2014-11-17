
long long S[12];
long long C[12][12];
long long A[12];
long long dp[12][12], rs[12];

void 
init(){
    A[1]=1;
    for(int i=2;i<12;i++) {
        A[i]=A[i-1]*i;
        
    }
    
    for(int i=0;i<12;i++){
        C[i][0]=1;
        C[i][i]=1;
        dp[i][1]=1;
        dp[i][i]=A[i];
    }
    for(int i=2;i<12;i++){
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    
    for(int i=3;i<12;i++) 
    {
        for(int j=2;j<i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*j;
        }
    }
    
    for(int i=1;i<12;i++)
    {
        for(int j=1;j<=i;j++)
        rs[i]+=dp[i][j];
    }
}

#include <iostream>
#include <cctype>
using namespace std;


int main()
{
    int T,N,c;
    long long cnt;
    init();
    cin>>T;
    for(c=1;c<=T;c++){
        cin>>N;
        cnt=0;
        for(int i=1;i<=N;i++)
        {
            cnt+=C[N][i]*rs[i];
        }
        cout<<c<<' '<<N<<' '<<cnt<<endl;
    }
}
