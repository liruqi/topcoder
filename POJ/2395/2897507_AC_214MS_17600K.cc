//Kruskal for MST 
//Problem: poj2395

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 2100
#define maxe 11000
int A[maxn];
struct edge{
	int u,v,l;
}E[maxe];
int U[maxn][maxn];

bool cmp(struct edge p,struct edge q){return p.l<q.l;}

int query(int u){
	while(A[u]>0)u=A[u];
	return u;
}

int main(){
	int N,M,i,j,u,v,l,et=0;
	memset(A,0xff,sizeof(A));
	memset(U,0xff,sizeof(U));
	scanf("%d%d",&N,&M);

	for(i=0;i<M;i++){
	
		scanf("%d%d%d",&u,&v,&l);
		if(U[u][v]<0){
			U[u][v]=et;
			U[v][u]=et;
			E[et].u=u;
			E[et].v=v;
			E[et].l=l;
			et++;
		}
		else E[U[u][v]].l <?= l;
	}
	sort(E,E+et,cmp);
	j=0;
	for(i=0;i<et;i++){
		struct edge &te=E[i];
		int rtu=query(te.u);
		int rtv=query(te.v);
		if(rtu!=rtv){
			A[rtu]=rtv;
			j>?=te.l;
		}
	}
	printf("%d\n",j);

	return 0;
}
