#include <stdio.h>
int degree;
int reduc(){
    int a, b, c;
    if(degree>2)return 1;
    if(degree<2)return 0;
    scanf("%d%d%d",&a,&b,&c);
    return b*b>=4*a*c;
}
int main(){
    scanf("%d",&degree);
    puts(reduc()?"NO":"YES");
}

