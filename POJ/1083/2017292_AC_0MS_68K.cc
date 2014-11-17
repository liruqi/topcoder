#include <stdio.h>
#include <algorithm>
using namespace std;
int cnt[201];

int main()
{
 	int T,N;
 	int i,j;
 	scanf("%d",&T);
 	while(T--){
		int st,en;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&N);
		for(i=0; i<N; i++){
			scanf("%d%d",&st,&en);
			st=(st+1)/2;
			en=(en+1)/2;
			if(st>en) 
			    swap(st, en);
			for(j=st; j<=en; j++) cnt[j]++;
		}
		for(i=1; i<201; i++)
		if(cnt[i]>cnt[0]) cnt[0]=cnt[i];
		printf("%d0\n",cnt[0]);
	}
	return 0;
}
