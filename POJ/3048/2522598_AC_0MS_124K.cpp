#include <stdio.h>
int maxfactor(int n){
    int i;
    for(i=2;i*i<=n;i++)if(!(n%i)){
        do
            n/=i;
        while(!(n%i));
        if(n==1) return i;
    }
    return n;
}

int main()
{
    int mf=0, mfn, N, n, pf;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&n);
        pf=maxfactor(n);
        if(pf>mf){
            mf=pf;
            mfn=n;
        }
    }printf("%d\n",mfn);
}
