#include<stdio.h>
#include<string.h>
int a[40040];
int lis[40040];//longest increasing sequence

int solve()
{
	int n,i,j,top=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(lis, 0x7f, 4*40040);
	lis[0]=0;
	for(i=1;i<=n;i++){
		/*
		for(j=top;j>=0;j--)
			if(lis[j] < a[i])
				break;
		*/
		int lw=0,up=top,md;
		while(lw<up){
			md=(lw+up)/2;
			if(lis[md]<a[i]) lw=md+1;
			else up=md-1;
		}
		if(lis[lw]>=a[i])lw--;
		j=lw;
		//printf("%d -> max point %d\n",j,lis[j]);
		if(lis[j+1]>a[i])
			lis[j+1]=a[i];
		if(j==top) top++;
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
