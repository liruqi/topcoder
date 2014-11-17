#include<stdio.h>

struct edge{int u,v,w;};
const int maxn = 50000+2;
int dist[maxn];
edge ea[maxn];
bool modify=1;

void relax(edge e){
	int can=dist[e.v]+e.w;
	if(dist[e.u]>can){
		modify=true;
		dist[e.u]=can;
	}
}

int main(){
	int N,i,j,u,v,w;
	scanf("%d",&N);
	for(i=N;i;i--){
		scanf("%d%d%d",&ea[i].u,&ea[i].v,&ea[i].w);
		ea[i].v++;ea[i].w*=-1;
	}
	while(modify){
		modify=false;
		for(i=N;i;i--)relax(ea[i]);
		for(i=1;i<maxn;i++){
			relax((edge){i,i-1,1});
			relax((edge){i-1,i,0});
		}
	}
	printf("%d\n",-dist[0]);
}