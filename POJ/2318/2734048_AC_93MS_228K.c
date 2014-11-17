#include <stdio.h>
#include <string.h>
#define maxn 5010

int n, m, x1, y1, x2, y2, xx, yy;
int U[maxn],L[maxn];
int C[maxn];

int getRelPos(int p){
	int xl=U[p]-L[p];
	int yl=y1 - y2;
	int xp=xx - L[p];
	int yp=yy - y2;
	if(xl*yp-xp*yl > 0) 
		return 1;	//bin right to the point
	xl = U[p+1]-L[p+1];
	xp = xx - L[p+1];
	if(xl*yp-xp*yl < 0) return -1;
	return 0;
}

int getBinId(){
	int low=0,up=n,mid;
	while(low<=up){
		mid = (low+up)/2;
		int t=getRelPos(mid);
		if(t<0)
			low = mid+1;
		else if(t==0)
			return mid;
		else
			up = mid-1; 
	}
	puts("???");
	return mid;
}

int main(){
	int i,j;
	while(scanf("%d",&n)!=EOF && n>0){
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		for(i=1;i<=n;i++)
			scanf("%d%d",U+i,L+i);
		U[0]=L[0]=x1;
		U[n+1]=L[n+1]=x2;
		memset(C,0,maxn*4);
		//solve
		for(i=0;i<m;i++)
			scanf("%d%d",&xx,&yy),C[getBinId()]++;;

		//output
		for(i=0;i<=n;i++)
			printf("%d: %d\n",i,C[i]);
			puts("");
	}
}
