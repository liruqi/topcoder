//1111

#include <stdio.h>

#include <string.h>



#define MAXN 21

int R,C,cnt;

char map[MAXN][MAXN];

char vst[MAXN][MAXN];



int dir[8][2]={{-1,0},{-1,1},{0,1}, {1,1},

               {1,0}, {1,-1},{0,-1},{-1,-1}

              };

bool vld(int r, int c){

    if(map[r][c]=='.')return 0;

    if(r>R || r<1)return 0;

    if(c>C || c<1)return 0;

    return 1;

}



void dfs(int r, int c){

    int i,rr,cc;

    if(vst[r][c])return;

    vst[r][c]=1;

    //printf("visit: %d %d\n",r,c);

    for(i=0;i<8;i++){

        rr=r+dir[i][0];

        cc=c+dir[i][1];

        if(vld(rr,cc)){

            dfs(rr,cc);

        }

        else {

            if((i%2) == 0)

            {

                cnt++;

                //printf("point: %d %d\n",rr,cc);

            }

        }

    }

}



int main(){

    int i,X,Y;

    while(~scanf("%d%d%d%d",&R,&C,&X,&Y) && R>0){

        memset(vst,0,MAXN*MAXN);

        for(i=1;i<=R;i++)

            scanf("%s",map[i]+1);

        cnt=0;

        dfs(X,Y);

        printf("%d\n",cnt);

    }

    return 0;

}
