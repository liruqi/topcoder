//bellman ford
#include<stdio.h>

struct edge{int u,v,w;};

const int maxn = 50000+2;

int dist[maxn];
edge ea[maxn];
bool modify;

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
	//memset(dist,0x7f,sizeof(dist));dist[0]=0;
	for(i=N;i;i--){
		//for each edge, relax
		modify=false;
		for(i=N;i;i--)relax(ea[i]);
		for(i=1;i<maxn;i++){
			relax((edge){i,i-1,1});
			relax((edge){i-1,i,0});
		}
		if(!modify)break;
		//cout<<"*"<<(-dist[0])<<endl;
	}
	printf("%d\n",-dist[0]);
	//cout<<(-dist[0])<<endl;
}