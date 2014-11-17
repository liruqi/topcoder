#include <stdio.h>
#define maxn 47000
typedef unsigned int uint;

uint dl[maxn],sl[maxn];
uint
digitsum(int n){
    int l=0;
    while(n){
        l++;n/=10;
    }
    return l;
}
void
init(){
    uint i;
    for(i=1;i<maxn;i++)
    dl[i]=digitsum(i);
    for(i=1;i<maxn;i++)
    sl[i]=sl[i-1]+dl[i];
}
uint getnthD(uint u, uint n){
    while(n--)
        u/=10;
    return u%10;
}

uint findD(int p){
    uint i,len=0,slen=0;
    for(i=0;len<p;){
        i++;
        len+=sl[i];
    }
    p-=len-sl[i];
    //printf("sequence pos to find: %u up to %u\n",p,i);
    for(i=0;slen<p;){
        i++;
        slen+=dl[i];
    }
    p=slen-p;
    //printf("find: %u th dig of num %u\n",p,i);
    return getnthD(i,p);
}

int main()
{
    uint tc,N;
    init();
    scanf("%u",&tc);
    while(tc-- && EOF!=scanf("%u",&N)){
        printf("%u\n", findD(N));
    }
}
