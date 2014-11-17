#include <stdio.h>
#include <math.h>
double A[300000];
int main(){
    int y,n,i;
    for(n=1;n<300000;n++){
        A[n] = log((n*2 + 1.0/3.0)*M_PI)/2.0;
        A[n] += log(n)*n - n;
    }
    
    while(~scanf("%d",&y) && y){
        y = y/10 - 194;
        double lnm = log(2)*(1<<y);
        for(n=1;A[n]<lnm;n++);
        printf("%d\n", n-1);
    }
    return 0;
}