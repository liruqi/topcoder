#include<math.h>
#include<algorithm>

double a,b,x,y;
int t;
int sol(){
    if(a>b) std::swap(a,b);
    if(x>y) std::swap(x,y);
    if(a<=x) return 0;
    if(a>x && b>y) return 1;
    double len=sqrt(x*x+y*y);
    double theta=asin(a/len);
    double alpha=asin(x/len);
    double beta =theta-alpha;
    return y*cos(beta)+x*sin(beta)<b;
}
int main(){
    scanf("%d",&t);
    while(t-- && -1!=scanf("%lf%lf%lf%lf",&a,&b,&x,&y))
    puts(sol()?"Escape is possible.":"Box cannot be dropped.");
}
