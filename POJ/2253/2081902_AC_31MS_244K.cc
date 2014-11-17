#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int Max=200;
struct point{
	int x,y;
	int root;
} P[Max];

struct edge{
	int st, en;
}E[Max*(Max+2)/2];

int EdgeLen(int s, int e){
	return (P[s].x-P[e].x)*(P[s].x-P[e].x) + (P[s].y-P[e].y)*(P[s].y-P[e].y);
}

int cmp(const void *a, const void *b){
	int asl=EdgeLen(((struct edge *)a)->st, ((struct edge *)a)->en);
	int bsl=EdgeLen(((struct edge *)b)->st, ((struct edge *)b)->en);
	return asl-bsl;
}

int findR(int x){
	int rt=x;
	while(P[rt].root >= 0)
		rt=P[rt].root;
	if(P[x].root >= 0)
		P[x].root=rt;
	return rt;
}

void Union(int x, int y){
	int r1=findR(x);
	int r2=findR(y);
	if(r1!=r2) P[r1].root=r2;
}

int Disjoint(){
	int r1=findR(0);
	int r2=findR(1);
	return (r1!=r2);
}

int main(){
	int i,j,k,N,tc=1;
	while(scanf("%d",&N) && N){
		for(i=0; i<N; i++){
			scanf("%d %d",&P[i].x, &P[i].y);
			P[i].root=-1;
		}
		for(i=0, k=0; i<N; i++){
			for(j=i+1; j<N; j++){
				E[k].st=i;
				E[k].en=j;
				k++;
			}
		}
		qsort(E, N*(N-1)/2, sizeof(E[0]), cmp);
		
		for(i=0; i< N*(N-1)/2 && Disjoint(); i++){
			Union(E[i].st, E[i].en);
		}
		i--;

		printf("Scenario #%d\n", tc++);
		printf("Frog Distance = %.3lf\n\n", sqrt( EdgeLen(E[i].st, E[i].en) ));
	}
	return 0;
}
