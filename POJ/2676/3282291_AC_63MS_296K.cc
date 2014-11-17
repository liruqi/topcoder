#include<algorithm>
#include<cstdio>

bool vst[9][9][10];
int cnt[9][9];
int idx[81],top;
char map[9][11];

bool cmp(int p,int q){ return cnt[p/9][p%9]<cnt[q/9][q%9]; }

void update(int r,int c){
    int i;
    int br=r/3*3;
    int bc=c/3*3;
    memset(vst[r][c],0,10);
    for(i=0;i<9;i++){
        vst[r][c][map[i][c]]=1;
        vst[r][c][map[r][i]]=1;
        vst[r][c][map[br+i/3][bc+i%3]] = 1;
    }
}

int dfs(int dep){
    if(dep==top) return 1;
    int r=idx[dep]/9;
    int c=idx[dep]%9;
    update(r,c);
    int i,k;
    for(k=1;k<=9;k++)
        if(!vst[r][c][k]){
            map[r][c]=k;
            if(dfs(dep+1))
                return 1;
        }
    map[r][c]=0;
    return 0;
}

void solve(){
    memset(cnt,0,sizeof(cnt));
    int r,c,i,j,k;
    for(r=0;r<9;r++){
        scanf("%s",map[r]);
        for(c=0;c<9;c++)map[r][c]-='0';
    }
    for(r=0;r<9;r++)
        for(c=0;c<9;c++)
        if(map[r][c]==0)
        {
            update(r,c);
            for(i=1;i<=9;i++)
            if(!vst[r][c][i])
                cnt[r][c]++;
	    }
	    
    top=0;
    for(r=0;r<9;r++)
        for(c=0;c<9;c++)
            if(!map[r][c])
                idx[top++]=r*9+c;
    std::sort(idx,idx+top,cmp);
    //for(r=0;r<top;r++) printf("%d\t", idx[r]);
    if(!dfs(0)) puts("failed");
    for(r=0;r<9;r++,puts(""))
        for(c=0;c<9;c++)
            putchar(map[r][c]+'0');
}

int main(){
    int ks;
    scanf("%d",&ks);
    while(ks--) solve();
}
