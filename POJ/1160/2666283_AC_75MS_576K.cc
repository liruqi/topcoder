#include <stdio.h>
#include <string.h>
#define absv(x) ((x>0)?(x):-(x))

int pos[310], V, P, cost[310][31], mdis[310][310]; 

int minCost(int st, int ed){
	int mid=(st+ed)/2, p, ds=0;
	for(p=st; p<=ed; p++){
		ds+=absv(pos[mid]-pos[p]);
	}
	return ds;
}

int main(){
	int i,j,k,ttc;	
	scanf("%d%d",&V,&P);
	memset(cost, 0x7f, (V+1)*31*4);
	
	for(i=1;i<=V;i++) scanf("%d",pos+i);
	for(i=1;i<V;i++)
		for(j=i+1;j<=V;j++){
			mdis[i][j]=minCost(i,j);
			//printf("%d ",mdis[i][j]);
		}
	for(i=1;i<=V;i++)
		cost[i][1]=mdis[1][i];
	for(i=1;i<V;i++){
		for(j=1;j<P;j++)
		{
			for(k=1;i+k<=V;k++){
				ttc=cost[i][j]+mdis[i+1][i+k];
				if(ttc < cost[i+k][j+1])
					cost[i+k][j+1]=ttc;
			}
		}
	}
	
	printf("%d\n",cost[V][P]);
}