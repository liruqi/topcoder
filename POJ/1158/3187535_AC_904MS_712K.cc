
#include<iostream>                
#include<queue>                       
#define mxv 301
#define inf 0xf0f0f0f
using namespace std;

int sour,dest,N,M;
int dist[mxv];
bool vst[mxv];
struct node{
	char ci[2];
	int rt,tb,tp;
}na[mxv];
struct edge{
	int u,w;
};

int wgt[mxv][mxv];
struct cmp{
	bool operator()(edge p,edge q){return p.w>q.w;}
};

int getcolor(int t,int u){
	int ret=na[u].ci[0];
	int rt=na[u].rt;
	int tb=na[u].tb;
	int tp=na[u].tp;
	if(t<rt) return ret;
	t-=rt;
	t%=(na[u].tb+na[u].tp);
	if(ret=='P')
		if(t<tb)
			return 'B';
		else 
		    return 'P';
	if(ret=='B')
		if(t<tp)
			return 'P';
		else 
		    return 'B';
}

int getctime(int t,int u){
	int ret=na[u].ci[0];
	int rt=na[u].rt;
	int tb=na[u].tb;
	int tp=na[u].tp;
	if(t<rt) return rt-t;
	t-=rt;
	int pd=na[u].tb+na[u].tp;
	t%=pd;
	if(ret=='P')
		if(t<tb)
			return tb-t;
		else 
			return pd-t;
	if(ret=='B')
		if(t<tp)
			return tp-t;
		else
			return pd-t;
}

int main(){
	cin>>sour>>dest
		 >>N>>M;
	int i;
	for( i=1;i<=N;i++) 
		cin>>na[i].ci>>na[i].rt>>na[i].tb>>na[i].tp;
	memset(wgt,0xf,sizeof(wgt));
	for(int i=0;i<M;i++){
		int u,v,w;
		cin>>u>>v>>w;
		wgt[u][v]=w;
		wgt[v][u]=w;
	}
	memset(dist,0xf,sizeof(dist));
	dist[sour]=0;
	priority_queue<edge,vector<edge>,cmp> pq;
	
	pq.push((edge){sour,0});
	while(pq.size()){
		
		edge now=pq.top();pq.pop();
		if(vst[now.u]) continue;
		//cout<<"pop: "<<now.u<<" "<<now.w<<endl;
		vst[now.u]=1;
		for(int v=1;v<=N;v++) if(!vst[v] && wgt[now.u][v]!=inf){//now.u -> v
			int uc=getcolor(now.w,now.u);
			int vc=getcolor(now.w,v);
			int dt=now.w;
			if(uc!=vc){
				int ut,vt;
				for(i=1;i<=3;i++)
				{
					ut=getctime(dt,now.u);
					vt=getctime(dt,v);
					if(ut==vt) dt+=ut;
					else break;
				}
				if(i==4) continue;//dead loop
				dt += min(ut,vt);
			}
			dt+=wgt[now.u][v];
			if(dt<dist[v]){
				dist[v]=dt;
				//cout<<"push: "<<v<<" "<<dt<<endl;
				pq.push((edge){v,dt});
			}
		}
	}
	if(dist[dest]==inf)puts("0");
	else printf("%d\n",dist[dest]);
}

