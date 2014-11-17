#include<stdio.h>
#include<string.h>
char prime[1000001];
int n,m;

int fpot(int x,int p){
    int ret=0;
    do{
        ret += x/p;
        x/=p;
    }while(x);
    return ret;
}
int cpot(int p){//combination pot function
    return fpot(n,p)-fpot(m,p)-fpot(n-m,p);
}
int modPow(int b,int e,int m){
    //printf("%d ^ %d\n",b,e);
    int c=b,ret=1;
    while(e){
        if(e&1) ret=ret*c%m;
        c=c*c%m;
        e/=2;
    }
    return ret;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    memset(prime,-1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(i=2;i*i<=n;i++) if(prime[i]) {
        for(j=i*i;j<=n;j+=i) prime[j]=0;
    }
    
    int pot2=cpot(2);
    int pot5=cpot(5);
    if(pot2<pot5) {
        puts("5");
        return 0;
    }
    pot2 -= pot5;
    int ld=modPow(2,pot2,10);//last digit
    prime[5]=0;
    for(i=3;i<=n;i++,ld%=10)
        if(prime[i])
            ld*=modPow(i, cpot(i), 10);
    printf("%d\n",ld);
}
