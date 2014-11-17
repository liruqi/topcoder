#include<algorithm>
#include<stdio.h>
int main()
{
    int n,x,k,cd,i,t;
    while(~scanf("%d%d%d",&n,&x,&k)){
        scanf("%d",&cd);
        for(i=2;i<=n;i++)scanf("%d",&t),cd=std::__gcd(cd,t);
        while(cd%k==0)cd/=k;
        puts(x%cd?"No":"Yes");
    }
}
