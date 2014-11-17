#include<stdio.h>
#include<algorithm>
#define inf 0x7fffffff
int N;
unsigned int slen[1100000], f, s, l;
int solve(){
    if(N<3) return 0;
    int i;
    f=inf,s=inf,l=0;
    for(i=0;i<N;i++) {
        scanf("%u",slen+i);
        if(slen[i]<s){
            s=slen[i];
            if(s<f) std::swap(f,s);
        }
        if(l<slen[i]) l=slen[i];
    }
    if(s+f>l) return 0;
    if(N>50) return 1;
    std::sort(slen,slen+N);
    for(i=1;i<N-1;i++)
        if(slen[i-1]+slen[i]>slen[i+1]) 
            return 1;
    return 0;
}
int main(){
    scanf("%d",&N);
    puts(solve()?"The set is accepted.":"The set is rejected.");
}
