#include<stdio.h>
#include<string.h>
#define maxn 2001
int A[maxn],w;
int query(int u, int &l){
	l=0;
	while(A[u]>0){
		w=u;
		u=A[u];
		l++;
	}
	return u;
}
int main(){
	int tc,N,ml,i,j=1,u,v,ul,vl,ur,vr;
	scanf("%d",&tc);
	while(j<=tc){
		char found = 0;
		scanf("%d%d",&N,&ml);
		memset(A,-1,4*maxn);
		for(i=1;i<=ml;i++){
			scanf("%d%d",&u,&v);
			ur=query(u, ul);
			vr=query(v, vl);
			if(ur!=vr){
				if((ul+vl)%2==0) A[ur]=vr;
				else (vl?(A[ur]=((ul+vl)%2)?w:vr):A[vr]=w);
			}
			else if((ul-vl)%2==0)
				found = 1;
		}
		printf("Scenario #%d:\n",j++);
		puts(found?"Suspicious bugs found!":"No suspicious bugs found!");
		puts("");
	}
	return 0;
}
