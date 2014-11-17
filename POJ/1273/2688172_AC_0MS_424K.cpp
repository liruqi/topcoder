#include <stdio.h>
#include <string.h>

#define MAXV 201

int cap[MAXV][MAXV], flow[MAXV][MAXV], E, V;
int lst[MAXV], que[MAXV], head, tail;

int bfs(){
    int u,v,minf,fd=0;
    head=0;
    que[0]=1;
    tail=1;
memset(lst, 0, (V+1)*4);
    while(head<tail){
        u=que[head++];
        for(v=1;v<=V;v++){
            if(!lst[v] && flow[u][v]<cap[u][v]){
                que[tail++]=v;
				lst[v]=u;
				if(v==V){

					break;
				}
			}
        }
    }
    if(!lst[V])
		return 0;
    v=V;
    minf=0x1fffffff;
    for(v=V; v!=1; v=lst[v])
		if(minf>cap[lst[v]][v]-flow[lst[v]][v])
			minf=cap[lst[v]][v]-flow[lst[v]][v];
    for(v=V; v!=1; v=lst[v]){
        flow[lst[v]][v]+=minf;
        flow[v][lst[v]]=-flow[lst[v]][v];
    }

    return minf;
}

int maxflow(){
    int r=0, inc;

    while(1){
        inc = bfs();
        r+=inc;
        if(inc==0)
            return r;
    }
    return 0;
}

int main(){
    int i,u,v,w;
    while(EOF!=scanf("%d%d",&E,&V)){
    	memset(flow,0,MAXV*MAXV*4);
        memset(cap ,0,MAXV*MAXV*4);
        for(i=1;i<=E;i++){
            scanf("%d%d%d",&u,&v,&w);
            cap[u][v]+=w;
        }
        printf("%d\n", maxflow());
    }
    return 0;
}
