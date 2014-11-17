//poj1330
#include<stdio.h>
#include<string.h>

#define maxn 10009

int A[maxn];
bool U[maxn];

int main(){
	int tc,N,i,u,v,w;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&N);
		memset(A,0,(N+1)<<2);
		memset(U,0,N+1);
		for(i=N-1;i>0;i--){
			scanf("%d%d",&u,&v);
			A[v]=u;
		}
		scanf("%d%d",&u,&v);
		w=u;
		do{
			U[w]=1;
			w=A[w];
		}while(w>0);
		w=v;
		do{

			if(U[w])break;
			w=A[w];
		}while(w>0);
		printf("%d\n",w);
	}
	return 0;
}
