#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxn 101000
int dat[maxn];
unsigned int idx[maxn],n,si,ti,k,q,cnt;
int cmp(int a,int b){
    return dat[a]<dat[b];
}

int main(){
    int i,j;
    scanf("%u%u",&n,&q);
    for(i=0;i<n;i++)scanf("%d",dat+i),idx[i]=i;
    sort(idx,idx+n,cmp);
    for(i=q;i>0;i--){
        cnt=0;
        scanf("%u%u%u",&si,&ti,&k);si--;ti--;
        for(j=0;j<n;j++)
            if(idx[j]>=si&&idx[j]<=ti){
                cnt++;
                if(!(cnt^k)){
                    printf("%d\n",dat[idx[j]]);
                    break;
                }
            }
    }
} 