#include <stdio.h>
#include <string.h>
const int dir[4][2]={{0,1},{1,0},
                     {0,-1},{-1,0}};
const int maxn=25;
char M[maxn][maxn];
bool U[30];
int R,C,maxl;

bool vld(int r,int c){
    if(r<0 || r>=R) return 0;
    if(c<0 || c>=C) return 0;
    return 1;
}


void dfs(int r, int c, int d){
    int i;
    if(U[M[r][c]-'A'])return;
    if(d>maxl) maxl=d;
    U[M[r][c]-'A']=1;
    for(i=0;i<4;i++) {
        int rr=r+dir[i][0];
        int cc=c+dir[i][1];
        if(vld(rr,cc))
            dfs(rr,cc,d+1);
    }
    U[M[r][c]-'A']=0;
}

int main(){
    int i,j;
    scanf("%d%d",&R,&C);
    for(i=0;i<R;i++)
        scanf("%s",M[i]);

    memset(U,0,30),dfs(0,0,1);

    printf("%d",maxl);
    return 0;
}
