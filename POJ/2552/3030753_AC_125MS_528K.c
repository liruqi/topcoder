#include <string.h>
#define maxn 50000

int s[maxn],t;
int aux[maxn];
int r[maxn];
int main(){
	int i,j,k,u;
	for(i=0;i<maxn;i++)s[i]=i+2;t=maxn;
	for(k=0;k<=3000;k++)
	{
		u=0;
		r[k]=s[0];
		for(i=1;i<t;i++)if((i%s[0]))aux[u++]=s[i];
		memcpy(s,aux,u*sizeof(int));
		t=u;
	}
	while(scanf("%d",&i),i)printf("%d\n",r[i-1]);
}
