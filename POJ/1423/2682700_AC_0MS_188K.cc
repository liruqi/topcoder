#include <stdio.h>
#include <math.h>

int main(){
    int t;
    double n;
    scanf("%d",&t);
    while(t-- && ~scanf("%lf",&n)){
        double lnf = log((n*2 + 1.0/3.0 )*M_PI)/2.0;
        
        lnf += log(n)*n - n;
        lnf /= log(10);
        if(lnf<1) lnf=1;
        printf("%.0lf\n", ceil(lnf));
    } 
    return 0;
}