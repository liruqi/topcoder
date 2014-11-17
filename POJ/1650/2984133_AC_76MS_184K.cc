//1650 binary search


#include <stdio.h>
#include <math.h>
#include <algorithm>
double a;
int main(){
	int i,n,d,l,x;
	scanf("%lf%d",&a,&l);
	double rn=1.0,rd=1.0;
	for(d=1;d<=l;d++){
		int low=0,up=l;
		while(low<up){
			//printf("*%d %d\n",low,up);
			double m = (low+up)/2;
			if(m/d<a)low=m+1;
			else up=m;
		}
		n=up;
		if(fabs(a-(double)n/d) > fabs(a-(double)(n-1)/d))
			n--;
		//printf("%d %d\n",n,d);
		if(fabs(a-rn/rd) > fabs(a - (double)n/d))
			rn = n,rd=d;
	}
	printf("%.0lf %.0lf\n",rn,rd);
}