#include<stdio.h>
#include<string.h>
#define maxn 110

int perm[210],N,k;
char buf[210];
int stk[210],top;
char vst[210];

void findPeriod(){
	int i,j,cnt;
	memset(vst,0,210);
	top=1;
	for(i=1;i<=N;i++)if(0==vst[i]){
		cnt=0;
		j=i;
		do{
			cnt++;
			vst[j]=top;
			j=perm[j];
		}while(!vst[j]);
		stk[top++]=cnt;
	}
}

void solve(){
	int i,j,p,len=strlen(buf);
	char ct[210];
	memset(ct,' ',210);
	buf[len]=' ';
	for(i=1;i<=N;i++){
		p=i;
		j = k % stk[vst[i]];
		while(j--) p=perm[p];
		ct[p]=buf[i];
	}
	for(i=1;i<=N;i++)putchar(ct[i]);
	puts("");
}

int main(){int i;
	while(scanf("%d",&N)==1 && N>0){
		for(i=1;i<=N;i++)
			scanf("%d",perm+i);
		findPeriod();
		while(scanf("%d",&k)==1 && k>0){
			memset(buf,' ',210);
			gets(buf);
			solve();
		}
		puts("");
	}
	return 0;
}
