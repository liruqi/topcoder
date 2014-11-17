#include <stdio.h>
typedef struct pf{
    int pn;
    int en;
}primeFactor;

primeFactor F[35];
int top;

void factorDecomp(int n)
{
    top=0;
    for(int i=2;i*i<=n;i++)if(!(n%i)){
        F[top].pn=i;
        F[top].en=0;
        while(0==(n%i))
        {
            n/=i;
            F[top].en++; 
        }
        top++;
    }
    if(n>1){
        F[top].pn=n;
        F[top].en=1;
        top++;
    }
}

#define mod 9901
int tab[mod];

int divSum(int pb, int epn)
{
    int rem, sum=0, i;
	tab[0]=1;
    for(i=1;i<mod-1;i++){
        tab[i] = tab[i-1]*pb;
		tab[i] %= mod;
    }
	for(i=0;i<mod-1;i++) 
		sum+=tab[i];
	sum %= mod;
	sum *= epn/(mod-1);
	rem = epn % (mod-1);
	for (i=0;i<=rem;i++)
		sum += tab[i];
    return sum % mod;
}


void solve(int b){
    int i,sum=1;
    for(i=0;i<top;i++){
        sum *= divSum(F[i].pn % mod, F[i].en*b);
        sum %= mod;
    }
    printf("%d\n",sum);
}


int main(){
    int A,B;
    while(~scanf("%d%d",&A,&B))
    {
        factorDecomp(A);
        solve(B);
    }
    return 0;
}