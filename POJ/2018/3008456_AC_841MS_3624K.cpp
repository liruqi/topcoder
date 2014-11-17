/*
2018
二分枚举答案
*/

#include <stdio.h>
#define maxn 110000
int N,F;
int org[maxn];
double rel[maxn];
double lft[maxn];
double rgt[maxn];
double sum[maxn];

int enough(double ave){
	int i;
	for(i=1;i<=N;i++)
		rel[i]=(double)org[i]-ave;
	lft[1]=0;
	rgt[N]=0;
	for(i=2;i<=N;i++){
		lft[i]=lft[i-1]+rel[i-1];
		if(lft[i]<0) lft[i]=0;
	}
	for(i=N-1;i>0;i--){
		rgt[i]=rgt[i+1]+rel[i+1];
		if(rgt[i]<0)rgt[i]=0;
	}
	rel[0]=0; sum[0]=0;
	for(i=0;i<F;i++)sum[0]+=rel[i];
	for(i=1;i+F-1<=N;i++){
		sum[i]=sum[i-1]-rel[i-1]+rel[i+F-1];
		if(sum[i]+lft[i]+rgt[i+F-1]>=0)
			return 1;
	}
	return 0;
}


int main(){
	int i;
	double up=2000000.0,lw=0,mid;
	scanf("%d%d",&N,&F);
	for(i=1;i<=N;i++)
		scanf("%d",org+i),org[i]*=1000;
	while(up-lw > 1e-1){
		mid = (up+lw)/2.0;
		if(enough(mid)) lw=mid;
		else up=mid;
	}
	printf("%d\n",(int)up);
	return 0;

}
