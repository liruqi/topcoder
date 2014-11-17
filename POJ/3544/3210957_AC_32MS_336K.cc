#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll price[1100] ,dist[1100],T;
int ans[1100];
struct vil{
    ll wp;
    int idx;
}V[1100];
struct pig{
    int wgt, idx;
}P[1100];

bool pcmp(pig p,pig q) { return p.wgt < q.wgt; }
bool vcmp(vil p,vil q) { return p.wp < q.wp; }


int N;
int main(){
	int i;
	while(scanf("%d%I64d",&N,&T)!=-1){
    	for(i=1;i<=N;i++) {
    		scanf("%I64d",&P[i].wgt);
    		P[i].idx=i;
    	}
    	for(i=1;i<=N;i++){
    		scanf("%I64d",&dist[i]);
    	}
    	for(i=1;i<=N;i++){
    		scanf("%I64d",&price[i]);
    		V[i].wp = price[i] - dist[i]*T;
    		V[i].idx=i;
    	}
    	sort(P+1,P+N+1,pcmp);
    	sort(V+1,V+N+1,vcmp);
    	for(i=1;i<=N;i++){
            ans[V[i].idx] = P[i].idx;
        }
    	for(i=1;i<=N;i++){
    		printf("%d%c", ans[i], i==N?'\n':' ');
    	}
    }
	return 0;
}
