#include <iostream>
#define MS (1<<15)
using namespace std;
int n,a[MS],c[1<<14];
main(){int i,x,t,p;scanf("%d",&n);for(i=0;i<n;i++){scanf("%d%*d",&x);x++;p=x;t=0;while(p)t+=a[p],p-=p&-p;while(x<MS)a[x]++,x+=x&-x;c[t]++;}for(i=0;i<n;i++)printf("%d\n",c[i]);}