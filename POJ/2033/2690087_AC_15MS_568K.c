#include <stdio.h>
#include <string.h>
#define maxn 100000
char cp[maxn];
int dp[maxn];
int len;
int count(){
    int i=1;
    dp[0]=1;
    dp[1]=1;
    for(i=1;i<len;i++){
        int n=(cp[i-1]-'0')*10 + cp[i]-'0';
        if(n%10 == 0) 
            dp[i+1]=dp[i-1];
        else if(n<27 && n>9)
            dp[i+1]=dp[i]+dp[i-1];
        else 
            dp[i+1]=dp[i];
    }
    return dp[len];
}

int main(){
    while(EOF!=scanf("%s",cp)&&strcmp(cp,"0")){
        memset(dp,0,maxn*sizeof(dp[0]));
        len=strlen(cp);
        printf("%d\n",count());
    }
    return 0;
}
