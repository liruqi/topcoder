//poj1742

#include <stdio.h>
#include <string.h>
#define maxp 100001
#define maxn 101
struct node{
	int val,cnt;
}nd[maxn];
char vst[maxp];
int idx[maxp];
int num[maxp];
int n,m;

int sol(){
	int i,j,l,r=0;
	memset(idx,0xff,sizeof(idx));
	memset(num,0xff,sizeof(num));
	memset(vst,0,   sizeof(vst));
	vst[0]=1;
	for(i=1;i<=n;i++)
		for(j=nd[i].val,l=0;j<=m;j++,l++)
			if(!vst[j] && vst[l]){
				if(idx[l]==i && num[l]>=nd[i].cnt)
					continue;
				idx[j]=i;
				if(idx[l]==i) num[j]=num[l]+1;
				else num[j]=1;
				vst[j]=1;
				r++;
				//printf("*%d\n",j);
			}
	return r;
}

int main(){
	int i;
	while(~scanf("%d%d",&n,&m) && n){
		for(i=1;i<=n;i++)scanf("%d",&nd[i].val);
		for(i=1;i<=n;i++)scanf("%d",&nd[i].cnt);
		printf("%d\n",sol());
	}
	return 0;
}
