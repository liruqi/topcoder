#include <stdio.h>
#include <algorithm>
using namespace std;

int S[22], N, edge;
bool U[22];

bool dfs(int ef, int cp, int cs){
	int i=cp;
	if(cp>N) return 0;
	if(ef>=4) return 1;
	for(;i<=N;i++) if(!U[i]){
		if(cs+S[i]<edge){
			//if(cs+2*S[i]<=cs)
            {
                U[i]=1;
				if(dfs(ef, i+1, cs+S[i]))
					return 1;
				U[i]=0;
            }
		}
		else if(cs+S[i]==edge){
            U[i]=1;
			if(dfs(ef+1, 1, 0))
				return 1;
			U[i]=0;
		}
		else 
            break;
	}
	return 0;
}

bool possible(){
	int i,sum=0;
	for(i=1;i<=N;i++)sum+=S[i];
	if(sum%4)return 0;
	edge=sum/4;
	for(i=1;i<=N;i++)
		if(S[i]>edge)
			return 0;
	sort(S+1,S+1+N);
	//reverse(S+1,S+1+N);
	return dfs(0, 1, 0);
}
int main(){
	int i,T;scanf("%d",&T);
	while(T--){
		memset(U,0,22);
		scanf("%d",&N);
		for(i=1;i<=N;i++)
			scanf("%d",S+i);
		puts(possible()?"yes":"no");
	}
	return 0;
}
