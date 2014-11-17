#include <stdio.h>
#include <string.h>
#define maxn 110
int max(int a, int b){
    return a>b?a:b;
}
int max(int a, int b, int  c){
    return max(a, max(b,c));
}

char s1[maxn], s2[maxn];
int dp[maxn][maxn], sl1, sl2;
int val[5][5]={
{5, -1, -2, -1, -3},
{-1,5,  -3, -2, -4},
{-2,-3, 5,  -2, -2},
{-1,-2, -2, 5,  -1},
{-3,-4, -2, -1, 0}
};

int c2d(char c){
    switch (c)
    {
        case 'A':return 0;
        case 'C':return 1;
        case 'G':return 2;
        case 'T':return 3;
        default: return 4;
    }
}

void init(){
    int i;
    for(i=1;i<=sl1;i++) s1[i] = c2d(s1[i]);//,printf("%u ",s1[i]);puts("");
    for(i=1;i<=sl2;i++) s2[i] = c2d(s2[i]);//,printf("%u ",s2[i]);puts("");
    memset(dp, 0, maxn*maxn*4);
    for(i=1;i<=sl1;i++) dp[i][0] = val[s1[i]][4]+dp[i-1][0];
    for(i=1;i<=sl2;i++) dp[0][i] = val[4][s2[i]]+dp[0][i-1];
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%s",&sl1, s1+1);
        scanf("%d%s",&sl2, s2+1);
        init();
        for(int i=1;i<=sl1;i++){
            for(int j=1;j<=sl2;j++){
                dp[i][j]=max(dp[i-1][j-1] + val[s1[i]][s2[j]],
                             dp[i][j-1] + val[4][s2[j]],
                             dp[i-1][j] + val[s1[i]][4]);
            }
        }
        //for(int i=0;i<=sl1;i++){ for(int j=0;j<=sl2;j++)printf("%d ",dp[i][j]); puts(""); }
        printf("%d\n",dp[sl1][sl2]);
    }
    return 0;
}
/*
3
7 AGTGATG
5 GTTAG
7 AGCTATT
9 AGCTTTAAA
*/
