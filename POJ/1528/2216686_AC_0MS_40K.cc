#include <stdio.h>

int main(){
    int n, i;
    puts("PERFECTION OUTPUT");
    while(scanf("%d",&n)!=EOF && n){
    printf("%5d  ",n);
    int cnt=1;

    for( i=2; i<=n/2; i++) if(n%i==0) cnt+=i;
    if(cnt>n) puts("ABUNDANT");
    else if(n==1 || cnt<n) puts("DEFICIENT");
    else puts("PERFECT");
    }//while
    puts("END OF OUTPUT");
    return 0;
}
