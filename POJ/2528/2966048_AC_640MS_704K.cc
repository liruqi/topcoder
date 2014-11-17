#include <iostream>
#include <list>
using namespace std;
const int maxn = 10001;

struct node{	int s,e,id;
};

node pp[maxn];
bool vs[maxn];
list<node> nl;
typedef list<node>::iterator lii;
int add(int id){
	int ps=pp[id].s, pe=pp[id].e, ret=0;
	node nn;
	nn.id=id;
	for(lii it=nl.begin(); it!=nl.end(); ++it){
		if(ps>pe) return ret;
		if(ps < it->s){
			nn.s=ps;
			nn.e=min(pe,it->s - 1);
			nl.insert(it, nn);
			ret=1;
		}
		ps >?= it->e + 1;
	}
	if(ps <= pe){
		nn.s = ps;
		nn.e = pe;
		nl.insert(nl.end(), nn);
		ret = 1;
	}
	return ret;
}

int main(){
	int n,ks,i;
	scanf("%d",&ks);
	while(ks--){
		nl.clear();
		scanf("%d",&n);
		for(i=n;i;i--)
			scanf("%d%d", &pp[i].s, &pp[i].e);
		int cnt=0;
		for(i=1;i<=n;i++)
			cnt+=add(i);
		printf("%d\n",cnt);
	}
}
