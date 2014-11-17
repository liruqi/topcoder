//poj3423
#include<stdio.h>
#include<stdlib.h>

int S,N;
int idx[2100];

int f2f(int n){
    int cnt=0;
    do
    {
        n/=2;
        cnt+=n;
    }while(n>1);
    return cnt;
}

int eoo(int id){
    if((1&(id+S))==0||id>=S) return 0;
    int n=S-1;
    int k=(id+n)/2;
    return f2f(n)==f2f(k)+f2f(n-k);
}

int solve(int si){
    int ret=0,i;
    for(i=0;i<N;i++)
        ret = (ret + eoo( abs(si-idx[i]))) & 1;
    return ret;
}

int main()
{
	int F,L,i,j;
	scanf("%d",&N);
	for(i=0;i<N;i++)
        scanf("%d",idx+i);
	scanf("%d%d%d",&S,&F,&L);
	for(i=0;i<L;i++)
	    printf(i==L?"%d\n":"%d ", solve(i+F));
	return 0;
}
