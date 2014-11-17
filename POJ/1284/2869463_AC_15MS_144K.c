#include <stdio.h>
int n,i,r;
phi(){
n--;r=n;
for(i=2;i*i<=n;i++)if(n%i==0){
do n/=i; while(n%i==0); r-=r/i;
}
if(n>1)r-=r/n;
}
main(){
while(~scanf("%d",&n))phi(),printf("%d\n",r);
}
