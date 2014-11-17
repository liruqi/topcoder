#define I(x) ~scanf("%d",&x)
int main(n,a,r,c,i){I(i);while(I(n)){r=c=0;for(i=n;i;i--){I(a);c+=a/2;r^=a;}puts((r>0)^(!c)?"John":"Brother");}}