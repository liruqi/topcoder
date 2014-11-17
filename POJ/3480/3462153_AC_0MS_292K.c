#define I(x) ~scanf("%d",&x)
int main(n,a,r,c){I(n);while(I(n)){r=c=0;for(;n;n--){I(a);c+=a/2;r^=a;}puts((r>0)^(!c)?"John":"Brother");}}