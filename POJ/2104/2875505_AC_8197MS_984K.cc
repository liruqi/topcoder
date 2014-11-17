#include <stdio.h>
#include <stdlib.h>
#define maxn 101000
int dat[maxn];
int idx[maxn];
int n,si,ti,k;
int cmp(const void *p,const void *q){
    int a=*(int*)p;
    int b=*(int*)q;
    return dat[a]-dat[b];
}

int main(){
    int i,j,q,cnt;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)scanf("%d",dat+i),idx[i]=i;
    qsort(idx,n,4,cmp);
    for(i=q;i;i--){
        cnt=0;
        scanf("%d%d%d",&si,&ti,&k);si--;ti--;
        for(j=0;j<n;j++)if(idx[j]>=si&&idx[j]<=ti){cnt++;if(!(cnt^k)){printf("%d\n",dat[idx[j]]);break;}}
    }
} 