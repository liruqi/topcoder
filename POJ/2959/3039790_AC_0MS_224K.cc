#include<stdio.h>
#include<math.h>
int T;
double D,d,S,t;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&D,&d,&S);
		t=(S+d)/(D-d);
		printf("%d\n",int(M_PI/asin(t)));
	}
}
