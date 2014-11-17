/*
模拟
从上往下,从左往右,找一个未清理的点
然后往右下方向走
把能够清理的全部清理掉
过程结束之后,地图自动清0
故不需要初始化 
*/
#include <stdio.h>
#define maxn 25
char M[maxn][maxn];

int clear(){
    int i,j,r,c,found=0;
    for(i=1;!found && i<=24;i++){
        for(j=1;j<=24;j++)
            if(M[i][j]){
                found=1;
                r=i;
                c=j;
                break;
            }
    }
    if(!found) return 0;
    for(i=r;i<=24;i++)
        for(j=c;j<=24;j++)
            if(M[i][j]){
                M[i][j]=0;
                r=i;
                c=j;
            }
    return 1;
}

int main()
{
    int row,col,cnt;
	while(1){
        //memset(M,0,maxn*maxn*4);
        scanf("%d%d",&row,&col);
        if(row<0) return 0;
        while(row>0){
            M[row][col]=1;
            scanf("%d%d",&row,&col);
        }
        
        cnt=0;
        while(clear())
            cnt++;
        printf("%d\n",cnt);
    }
}
