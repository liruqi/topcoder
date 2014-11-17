#include <stdio.h>
#include <string.h>
#define maxn 21
int dp[21][21][21];
char fd[21][21][21];


int dfs(int a,int b,int c){
    if(a<=0 || b<=0 || c<=0) {
        return 1;
    }
    else if(a>20 || b>20 || c>20){
        return dfs(20,20,20);
    }
    //#define sub [a][b][c]
    if(!fd [a][b][c]){
        if((a<b) && (b<c)){
            dp [a][b][c] = dfs(a, b, c-1) + dfs(a, b-1, c-1) - dfs(a, b-1, c);
            fd [a][b][c] = 1;
        }
        else {
            dp [a][b][c] = dfs(a-1, b, c) + dfs(a-1, b-1, c) + dfs(a-1, b, c-1) - dfs(a-1, b-1, c-1);
            fd [a][b][c] = 1;
        }
    }
    return dp [a][b][c];
}

int main(){
    int a,b,c;
    while(3==scanf("%d%d%d",&a,&b,&c)&&(a!=-1||b!=-1||c!=-1))
        printf("w(%d, %d, %d) = %d\n",a,b,c,dfs(a,b,c));
    return 0;
}