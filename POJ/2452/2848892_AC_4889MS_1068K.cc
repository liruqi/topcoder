#include <stdio.h>
int A[51000],i,n;
int solve(int beg, int end){
	for(i=beg; i<end&&A[i]>A[i+1]; i++); beg=i;
	if(beg>=end) return -1;
	int mxi=beg;
	for(i=beg+1; i<=end; i++) if(A[i]>A[mxi]) mxi=i;
	int mni=beg;
	for(i=beg+1; i<=mxi; i++) if(A[i]<A[mni]) mni=i;
	int ret=mxi-mni;
	ret >?= solve(beg, mni-1);
	ret >?= solve(mxi+1, end);
	return ret;
}
int main(){
	while(~scanf("%d",&n)) {
		for(i=1;i<=n;i++) scanf("%d",A+i);
		printf("%d\n",solve(1,n));
	}
}
