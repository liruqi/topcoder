//poj2236
#include <stdio.h>
#include <set>
using namespace std;
const int maxn = 1010;
int N,D;
typedef struct point{
	int x,y;
}pit;
pit P[maxn];

set<int> G[maxn];
int diss(int p,int q){
	int x=P[p].x-P[q].x;
	int y=P[p].y-P[q].y;
	return x*x+y*y;
}
void graph(){
	int i,j;
	int ds = D*D;
	for(i=1;i<=N;i++)
		for(j=i+1;j<=N;j++)
			if(diss(i,j)<=ds)
				G[i].insert(j),G[j].insert(i);
}
int A[maxn];
bool O[maxn];
int root(int x){
	while(A[x]) x=A[x];
	return x;
}
int main(){
	int i,u,v;
	char cmd[3];
	scanf("%d%d",&N,&D);
	for(i=1;i<=N;i++) scanf("%d%d",&P[i].x,&P[i].y);
	graph();
	while(~scanf("%s",cmd)){
		if(cmd[0]=='O') {
			scanf("%d",&u);
            O[u]=1;
			int p=root(u);
			for(set<int>::iterator it=G[u].begin(); it!=G[u].end(); ++it){
				v=*it;
				if(O[v]){
				    int q=root(v);
				    if(p!=q) A[q]=p;
                }
			}
		}
		else {
			scanf("%d%d",&u,&v);
			int p=root(u);
			int q=root(v);
			puts(p==q?"SUCCESS":"FAIL");
		}
	}
	return 0;
}
