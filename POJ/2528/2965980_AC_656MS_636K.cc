#include <cstdio>
#include <list>
#include <cstring>
using namespace std;
const int maxn = 10001;

typedef struct _node{
	int s,e,id;
}node;

node pp[maxn];
bool vs[maxn];
list<node> nl;
typedef list<node>::iterator lii;

void add(int id){
	int ps=pp[id].s, pe=pp[id].e;
	node nn;
	nn.id=id;
	for(lii it=nl.begin(); it!=nl.end(); ++it){
		if(ps>pe) break;
		if(ps < it->s){
			nn.s=ps;
			nn.e=min(pe,it->s - 1);
			nl.insert(it, nn);
		}
		ps >?= it->e + 1;
	}
	if(ps <= pe){
		nn.s = ps;
		nn.e = pe;
		nl.insert(nl.end(), nn);
	}
}

int main(){
	int n,ks,i;
	scanf("%d",&ks);
	while(ks--){
		nl.clear();
		scanf("%d",&n);
		for(i=n;i;i--){
			scanf("%d%d", &pp[i].s, &pp[i].e);
		}
		for(i=1;i<=n;i++){
			add(i);
		}
		memset(vs,0,maxn);
		for(lii it=nl.begin(); it!=nl.end(); ++it){
			vs[it->id]=1;
		}
		int cnt=0;
		for(i=1;i<=n;i++)
			if(vs[i])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
