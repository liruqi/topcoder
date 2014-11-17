#include <stdio.h>
#include <string.h>
#include <math.h>
#define absv(x) ((x>0)?(x):-(x))

int pos[310], V, P, cost[310][31]; 

int minCost(int st, int ed){
	int mid=(st+ed)/2,p;
	int ds=0;
	for(p=st; p<=ed; p++){
		ds+=absv(pos[mid]-pos[p]);
	}
	return ds;
}

int main(){
	int i,j,k,ttc;
	memset(cost, 0x7f, 310*31*4);
	scanf("%d%d",&V,&P);
	
	for(i=1;i<=V;i++) scanf("%d",pos+i);
	for(i=1;i<=V;i++)
		cost[i][1]=minCost(1,i);
	for(i=1;i<V;i++){
		for(j=1;j<P;j++)
		{
			//printf("%d\t",cost[i][j]);
			for(k=1;i+k<=V;k++){//find cost from 1 to i+k`th village with j+1 post office
				ttc=cost[i][j]+minCost(i+1, i+k);
				if(ttc < cost[i+k][j+1])
					cost[i+k][j+1]=ttc;
			}
		}
		//puts("");
	}
	
	printf("%d\n",cost[V][P]);
}