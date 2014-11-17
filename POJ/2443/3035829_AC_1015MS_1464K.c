#include <stdio.h>
int n,i,j,k,x,y,id[10001][32];

int exist(){
	for(i=0;i<32;i++)if(id[x][i]&id[y][i])return 1;return 0;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&j);
		x=i/32;y=i%32;
		while(j--){
			scanf("%d",&k);
			id[k][x]|=(1<<y);
		}
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		puts(exist()?"Yes":"No");
	}
}