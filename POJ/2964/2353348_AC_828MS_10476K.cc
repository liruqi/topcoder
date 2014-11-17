#include <string.h>
#include <stdio.h>
#define max(x, y) ((x)>(y))?(x):(y)
const int maxn = 110;
const char blk = '#',il='*';
char M[maxn][maxn];
int dp[2*maxn][maxn][maxn];
int T,R,C;

int vp(int x,int y){
    if(x>=C||x<0||y>=R||y<0) 
    return 0;
    return 1;
}

int findmax(int p, int x1, int x2)
{
    int mil=0;
    int y1=p-x1,y2=p-x2;
    if(vp(x1-1,y1) && M[y1][x1-1]!=blk){
        if(vp(x2-1,y2) && M[y2][x2-1]!=blk)
			mil=max(mil,dp[p-1][x1-1][x2-1]);
        if(vp(x2,y2-1) && M[y2-1][x2]!=blk)
			mil=max(mil,dp[p-1][x1-1][x2]);
    }
    if(vp(x1,y1-1) && M[y1-1][x1]!=blk){
        if(vp(x2-1,y2) && M[y2][x2-1]!=blk)
			mil=max(mil,dp[p-1][x1][x2-1]);
        if(vp(x2,y2-1) && M[y2-1][x2]!=blk)
			mil=max(mil,dp[p-1][x1][x2]);
    }
    if(x1!=x2) {
        if(M[y1][x1]==il) mil++;
        if(M[y2][x2]==il) mil++;
    }
    else {
        if(M[y1][x1]==il) mil++;
    }
    return mil;
}

int main()
{
    int i,j,k;
	scanf("%d",&T);
    while(T-- && scanf("%d%d",&C,&R)!=EOF){
        for(i=0;i<R;i++)
            scanf("%s",M[i]);
	memset(dp,0,sizeof(dp));
        dp[0][0][0]=(M[0][0]==il)?1:0;
        for(i=1;i<=R+C-2;i++)
        for(j=0;j<=i&&j<C;j++) if(M[i-j][j]!='#' && (i-j)<R)
        for(k=0;k<=i&&k<C;k++) if(M[i-k][k]!='#' && (i-k)<R)
		dp[i][j][k]=findmax(i,j,k);
        printf("%d\n",dp[R+C-2][C-1][C-1]);
    }
    return 0;
}
