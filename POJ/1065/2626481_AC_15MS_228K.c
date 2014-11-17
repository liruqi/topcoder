#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <algorithm>
//using namespace std;

#define maxn 5100
typedef
struct stick{
	int l,w;
}Stk;
Stk S[maxn];
/*
bool cmp(Stk p,stk q){
	if(p.w-q.w)return p.w<q.w;
	return p.l-q.l;
}*/
int cmp(const void *p, const void *q){
	Stk *j=(Stk*)p, *k=(Stk*)q;
	if(j->w-k->w)return j->w-k->w;
	return j->l-k->l;
}

int mt[maxn];	//max tail length
int solve(){
   int n,i,j,cnt=1; scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&S[i].l,&S[i].w);
	qsort(S+1,n,sizeof(Stk),cmp);
	memset(mt,0,4*(n+1));
	for(i=1;i<=n;i++) {
		for(j=1;j<=cnt;j++)
			if(S[i].l>=mt[j]) {
				mt[j]=S[i].l;
				break;
			}
		if(j>cnt) {
			cnt++;mt[cnt]=S[i].l;
		}
	}
	return cnt;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) printf("%d\n",solve());
	return 0;
}
