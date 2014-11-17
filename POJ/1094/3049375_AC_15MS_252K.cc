//poj 1094
#include <stdio.h>

#include <string.h>

#include <algorithm>

bool les[26][26],adj[26][26];
int degree[26];
int n, m;
int idx[26];
int mul;

int slv(){
	int i,j,k;
	memset(degree,0,sizeof(degree));
	memcpy(adj,les,sizeof(adj));
	for(k=0;k<n;k++)
	for(i=0;i<n;i++)if(adj[i][k])
	for(j=0;j<n;j++)if(adj[k][j])
	adj[i][j]=1;
	for(i=0;i<n;i++)if(adj[i][i])return 2;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)if(adj[i][j])degree[i]++;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)if(i^j){
		if(degree[i]>degree[j]){
		if(!adj[i][j])return 0;
		}
		else if(degree[i]<degree[j]){
		if(!adj[j][i])return 0;
		}
		else return 0;
	}
	return 1;
}
bool cmp(int p,int q){return degree[p]>degree[q];}
void prt(){
	int i;
	for(i=0;i<n;i++)idx[i]=i;
	std::sort(idx,idx+n,cmp);
	for(i=0;i<n;i++)putchar(idx[i]+'A');
	puts(".");
}
void pg(){
int i,j;
for(i=0;i<n;i++,puts(""))
for(j=0;j<n;j++)printf("%d ",les[i][j]);
puts("***");
for(i=0;i<n;i++,puts(""))
for(j=0;j<n;j++)printf("%d ",adj[i][j]);
}

int main()

{
	int i,j,fd;
	char rel[10];
	while(scanf("%d%d",&n,&m), n){
		fd=0;
		memset(les,0,sizeof(les));
		for(i=1;i<=m;i++){
		scanf("%s",rel);
		if(fd) continue;
		les[rel[0]-'A'][rel[2]-'A']=1;
		j=slv();
		//pg();
		if(j==1) {
			printf("Sorted sequence determined after %d relations: ",i);
			prt();
			fd=1;
		}
		else if(j==2){
			printf("Inconsistency found after %d relations.\n", i);
			fd=1;
		}
	}
	if(!fd)puts("Sorted sequence cannot be determined.");
	}

}
