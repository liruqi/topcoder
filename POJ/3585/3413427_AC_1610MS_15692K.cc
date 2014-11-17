//poj 3585
//国防科大A
//去递归
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;

struct edge{
	int t,w;
};
typedef vector<edge> lit;
typedef lit::iterator lii;
#define mx 200001
#define inf mx
lit adj[mx];
int mxf[mx],upf[mx],dnf[mx],n;

int que[mx],prev[mx],wgt[mx],head,tail;
int b2t_bfs(){
    head=tail=0;
    prev[tail]=-1;
    que[tail]=1;
    tail++;
    while(head<tail){
        int u=que[head];
        lit &now=adj[u];
	    //if(now.size()==1 && prev[u]!=0)continue;
	    for(lii it=now.begin();it!=now.end();++it)
		if(it->t != que[prev[head]]){
			que[tail]=it->t;
			wgt[tail]=it->w;
			prev[tail]=head;
			tail++;
		}
		head++;
    }
    memset(mxf,0,sizeof(mxf));
    memset(upf,0,sizeof(mxf));
    
    for(int i=tail-1;i>0;i--){
        if(adj[que[i]].size()==1 && prev[que[i]]!=-1){
            upf[i]=wgt[i];
        } else {
            upf[i]=min(mxf[i],wgt[i]);
        }
        mxf[prev[i]]+=upf[i];
    }
}

int t2b_bfs(){
    for(int i=1;i<tail;i++){
        // if father is root and root is a leaf
        if(prev[i]==0 && adj[1].size()==1){
            dnf[i]=wgt[i];
        } else {
            dnf[i]=min(wgt[i], mxf[prev[i]]-upf[i]);
        }
        mxf[i]+=dnf[i];
    }
}

int main(){
	int ks;
	scanf("%d",&ks);
	while(ks--){
		int i,s,t,w;
		scanf("%d",&n);
		for(i=n;i;i--)
			adj[i].clear();
		for(i=n-1;i;i--){
			scanf("%d",&s);
			scanf("%d",&t);
			scanf("%d",&w);
			adj[s].push_back((edge){t,w});
			adj[t].push_back((edge){s,w});
		}

		b2t_bfs();
		t2b_bfs();
		printf("%d\n",*max_element(mxf,mxf+n));
	}
}
/*
2
5
1 2 1
1 3 2
3 4 3
3 5 4
4
1 2 1
2 3 2
2 4 3
*/
