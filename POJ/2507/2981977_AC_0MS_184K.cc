//2507

#include <stdio.h>
#include <math.h>

#define min(a,b) ((a<b)?(a):(b))


double x,y,c,w;
double f(double w){
	double p=sqrt(y*y-w*w);
	double q=sqrt(x*x-w*w);
	return c/p+c/q;
}

int main(){
	while(~scanf("%lf%lf%lf",&x,&y,&c)){
		double m,h=min(x,y),l=0;
		h = sqrt(h*h - c*c);
		while(h-l>1e-4){
			m = (h+l)/2;
			if(f(m)<1.0) l=m;
			else h=m;
		}
		printf("%.3lf\n",l);
	}

}
