#include <stdio.h>

int dgr[110000],n,d,c,s;
int find(int g){
	if(g<=d)return 0;return 1+find(g-d+1);
}
int main()
{
	int i;scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++)scanf("%d",&c),dgr[c]++;
	for(i=0;i<=n;i++)s+=find(dgr[i]);
	printf("%d",s);
}