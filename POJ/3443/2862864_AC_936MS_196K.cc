#include <stdio.h>
#include <string.h>
int N,S,G,maxl;
int L[13];
int K[13],top;
char Us[13],Up[110];
int div3(int c){
	int i,j=1,m=99;
	S=top=0;
	for(i=0;i<N;i++,j<<=1)
		if(j&c)
			S+=L[i],K[top++]=L[i],m<?=L[i];
	if(top<6||S%3) return 0;
	for(G=S/3,i=0;i<top;i++)
		if(K[i]+m>G)
			return 0;
	return 1;
}
int dfs(int li,int cl){
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
			if (G>maxl && sol())
				maxl=G;
		}
		printf("Case %d: %d\n",t++,maxl);
	}
	return 0;
}