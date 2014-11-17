#include<stdio.h>
int i,N,M;

int mny[100000];

int enough(int x){
	int s=0, c=0, nxt=0;
	for(i=0;i<N;i++) {
		nxt=s+mny[i];
		if(nxt>x)
			s=mny[i], c++;
		else s=nxt;
	}
	s?c++:1;
	return c<=M;
}


int main()

{
	int low=0, high, mid, sum=0;

    scanf("%d%d", &N,&M);
    for(i=0;i<N;i++) scanf("%d",mny+i), sum+=mny[i], low>?=mny[i];
    high = sum;

	while(low<high){
		mid=(low+high)/2;
		//printf("*%d\n",mid);
		if(enough(mid))high=mid-1;
		else low=mid+1;
	}
	printf("%d\n",low);

}
