#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 110
typedef struct edge{
	int u,v,w;
}Edge;

Edge E[MAXN*MAXN/2];
int n,m,tc,tot_cost;
int R[MAXN];

int root(int u){
	while(R[u]>0) u=R[u];
	return u;
}

bool unique(){
	int i,cnt;
	bool u=1;
	bool g;//good edge
	tot_cost=0;
	memset(R,0xff,MAXN*4);
	for(i=cnt=0;cnt<n && i<m;i++){
		int ur=root(E[i].u);
		int vr=root(E[i].v);
		if(ur!=vr){
			g=0;
			if(i+1<m && E[i].w==E[i+1].w)
			{
				int nur=root(E[i+1].u);
				int nvr=root(E[i+1].v);
				if(nur!=nvr) g=1;
			}
			R[ur]=vr;
			if(g){
				int nur=root(E[i+1].u);
				int nvr=root(E[i+1].v);
				if(nur==nvr) u=0;
			}
			tot_cost+=E[i].w;
			cnt++;
		}
	}
	return u;
}

bool cmp(struct edge p,struct edge q){return p.w<q.w;}
int main(){
	int i,et;
	scanf("%d",&tc);
	while(tc--){
		et=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
		sort(E,E+m,cmp);
		if(unique())printf("%d\n",tot_cost);
		else puts("Not Unique!");
	}
	return 0;
}