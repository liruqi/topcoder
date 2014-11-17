//poj2560
#define maxn 101
#include <math.h>
#include <stdio.h>
#include <algorithm>

struct node{
	double x,y;
}na[maxn];
struct edge{
	int u,v;double w;
	edge(){}
	edge(int u,int v,double w):u(u),v(v),w(w){}
}ea[maxn*maxn];
int A[maxn*maxn];
double dist(node a,node b){
	double dx=a.x-b.x, dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int root(int u){
	int rt=u;
	while(A[rt])rt=A[rt];
	if(rt^u)A[u]=rt;
	return rt;
}
int N,top;
int main(){
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++)scanf("%lf%lf",&na[i].x,&na[i].y);	
	for(i=1;i<=N;i++)for(j=1;j<i;j++)ea[top++]=edge(i,j,dist(na[i],na[j]));
	std::sort(ea,ea+top,cmp);
	double res=0;
	for(i=0;i<top;i++){
	edge &nd=ea[i];
	int ru=root(nd.u), rv=root(nd.v);
	if(ru!=rv)A[ru]=rv,res+=nd.w;
	}
	printf("%.2lf",res);
}
/*
Sample Input

3
1.0 1.0
2.0 2.0
2.0 4.0

Sample Output

3.41
*/
