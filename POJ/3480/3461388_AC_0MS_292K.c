#define I(x) scanf("%d",&x);
int main(n,k,a,r,c,i){I(k)while(k--){I(n)r=c=0;for(i=n;i;i--){I(a)if(a<2)c++;r^=a;}puts((r>0)^(c==n)?"John":"Brother");}}