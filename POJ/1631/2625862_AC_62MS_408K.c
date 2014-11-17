#include<stdio.h>
#include<string.h>
int a[40040];
int lis[40040];

int solve()
{
	int n,i,j,top=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(lis, 0x7f, 4*(n+1));
	lis[0]=0;
	for(i=1;i<=n;i++){
		int lw=0,up=top,md;
		if(lis[top]<a[i]) {lis[top+1]=a[i];top++;}
		else {
		while(lw<up){
			md=(lw+up)/2;
			if(lis[md]<a[i]) lw=md+1;
			else up=md-1;
		}
		if(lis[lw]>=a[i])lw--;
		j=lw;

		if(lis[j+1]>a[i])
			lis[j+1]=a[i];
		}
	}
	return top;
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		printf("%d\n",solve());
	return 0;
}
