#include<stdio.h>
#include<math.h>
static double pi=3.1415926535898 ;
int main(){
	double xx1,yy1,xx2,yy2;
	double a1, a2;
	double fenzi, x, y;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf",&xx1,&yy1,&a1,&xx2,&yy2,&a2);
		a1=-a1*pi/180.0; a2=-a2*pi/180.0;
		fenzi=(xx1*cos(a1)+yy1*sin(a1))*sin(a2)-(xx2*cos(a2)+yy2*sin(a2))*sin(a1);
		x=fenzi/sin(a2-a1);
		fenzi=(xx1*cos(a1)+yy1*sin(a1))*cos(a2)-(xx2*cos(a2)+yy2*sin(a2))*cos(a1);
		y=fenzi/sin(a1-a2);
		printf("%.4lf %.4lf\n", x, y);
	}
	return 0;
}
