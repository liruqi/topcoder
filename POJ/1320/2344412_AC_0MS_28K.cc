#include <stdio.h>
#include <math.h>

int main()
{
    long long h, n;
    int cnt=0;
    for(n=2; cnt<10; n++) {
        long long m;
        if(n%2){
            h=(1+n*n)/2;
            m=sqrt(h);
            if(m*m == h){
                printf("%10I64d%10I64d\n",m*n,n*n);
                cnt++;
            }
        }
        else {
            h=2*n*n+1;
            m=sqrt(h);
            if(m*m == h){
                printf("%10I64d%10I64d\n",m*n,2*n*n);
                cnt++;
            }
        }
    }
    getchar();
}
//%I64d
