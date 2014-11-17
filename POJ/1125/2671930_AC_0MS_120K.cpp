#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 110
int max(int a, int b){return a>b?a:b;}
int tdt, N;
int dist[maxn][maxn], mIdx[maxn];
#define INF 0x1f1f1f1f

int main()
{
    int i,j,k,cnt,fts;
    while(EOF!=scanf("%d",&N) && N>0){
        memset(dist, 0x1f, maxn*maxn*4);
        for(i=1;i<=N;i++){
        	dist[i][i]=0;
            scanf("%d",&cnt);
            while(cnt--){
                scanf("%d%d",&j,&tdt);
                dist[i][j]=tdt;
            }
        }
        for(k=1;k<=N;k++)
           	for(i=1;i<=N;i++)
           		for(j=1;j<=N;j++)
            	{
            		if(dist[i][j]>dist[i][k]+dist[k][j])
            			dist[i][j]=dist[i][k]+dist[k][j];
            	}
            	/*
        for(i=1;i<=N;i++){
        	for(j=1;j<=N;j++)printf("%d",dist[i][j]);
        	puts("");
        }*/
        for(i=1;i<=N;i++){
        	mIdx[i]=1;
        	int *th=dist[i];
        	for(j=1;j<=N;j++)
        		if(th[j]==INF)
        		{
        			mIdx[i]=-1;
        			break;
        		}
        		else {
        			if(th[j]>th[mIdx[i]])
        			mIdx[i]=j;
        		}
        	//printf("Idx %d : %d\n",i,mIdx[i]);
        }
        fts=-1;
        for(i=1;i<=N;i++)if(mIdx[i]>0)
        {
            if(fts < 0) fts=i;
            else if(dist[i][mIdx[i]] < dist[fts][mIdx[fts]])
                fts=i;
        }
        fts>0?(printf("%d %d\n",fts, dist[fts][mIdx[fts]]) ): (puts("disjoint") );
    }
}
