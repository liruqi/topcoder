//2192
#include <iostream>
using namespace std;
#define maxl 1001
char A[maxl],B[maxl],C[maxl];
bool dp[maxl][maxl];
int main(){
    int tc,k,i,j,al,bl,cl;
    cin>>tc;
    for(k=1;k<=tc;k++){
    	memset(dp,0,sizeof(dp));
    	cin>>(A+1)>>(B+1)>>(C+1);
    	al=strlen(A+1);bl=strlen(B+1);cl=strlen(C+1);dp[0][0]=1;
    	for(i=1;i<=al && A[i]==C[i];i++) dp[i][0]=1;
    	for(i=1;i<=bl && B[i]==C[i];i++) dp[0][i]=1;
    	for(i=1;i<=al;i++)
    		for(j=1;j<=bl;j++){
    			if(dp[i][j-1] && B[j]==C[i+j]) dp[i][j]=1;
    			if(dp[i-1][j] && A[i]==C[i+j]) dp[i][j]=1;
    		}
    	cout<<"Data set "<<k<<(dp[al][bl]?": yes":": no")<<endl;
    }
    return 0;
}
