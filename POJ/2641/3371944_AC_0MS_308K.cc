#include<map>
#include<set>
#include<stdio.h>
#include<math.h>

using namespace std;
int a,b,s,m,n;
int main(){
	
	while(1){
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&s);
		scanf("%d",&m);
		scanf("%d",&n);
		if(!a) break;
		double v=a*m;
		double h=b*n;
		double alp = atan(h/v);
		double d=sqrt(v*v+h*h);
		printf("%.2lf %.2lf\n", alp*180.0/3.14159265358979323846,d/s);
	}
}
