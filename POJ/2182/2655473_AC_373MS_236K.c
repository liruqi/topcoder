#include<stdio.h>
#define maxn 8001
char Usd[maxn];
int Ord[maxn], Pre[maxn];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		scanf("%d",Pre+i);
	for(i=n;i>0;i--){
        for(j=1;j<=n;j++)
            if(!Usd[j]){
                if(Pre[i]<=0)break;
                Pre[i]--;
            }
        Ord[i]=j;
        Usd[j]=1;
    }
    for(i=1;i<=n;i++)
		printf("%d\n",Ord[i]);
	return 0;
}