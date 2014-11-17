#include <stdio.h>
#include <string.h>


int N,S,G,maxl;//sum, segLength=sum/3
int L[13];
int K[13],top;
char Us[13],Up[110];

int div3(int c){
	int i,j=1;
	S=top=0;
	for(i=0;i<N;i++,j<<=1)
		if(j&c)
			S+=L[i],K[top++]=L[i];
	if(top<6||S%3) return 0;
	for(G=S/3,i=0;i<top;i++)
		if(K[i]>=G)
			return 0;
	return 1;
}
//long stick id, cur length
int dfs(int li,int cl){
    if(cl>G){puts("error!");return 0;}
	if(cl==G){
		if(li>=3) return 1;
		else return dfs(li+1,0);
	}
	int i,cp;
	for(i=0;i<top;i++) if(!Us[i]&&(cp=cl+K[i])<=G&&(!Up[cp]||cp==G)){
		Us[i]=1; Up[cp]=1;
		if(dfs(li,cp)) return 1;
		Us[i]=0; Up[cp]=0;
	}
	return 0;
}

int sol(){
	//printf("try len %d\n",G);
	if(G<maxl) return 0;
	memset(Us,0,sizeof(Us));
	memset(Up,0,sizeof(Up));
	return dfs(1,0);
}

int main(){
	int i,t=1;
	while(~scanf("%d",&N) && N>0){
		maxl=0;
		for(i=0;i<N;i++)scanf("%d",L+i);
		for(i=(1<<N)-1;i;i--) if(div3(i)){
			//printf("run id=%d\n",i);
			if (sol() && G>maxl)
				maxl=G;
		}

		printf("Case %d: %d\n",t++,maxl);
	}
	return 0;
}