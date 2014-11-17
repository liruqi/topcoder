#include <stdio.h>

const int maxn=500000;
int A[maxn], B[maxn];
int N;
__int64 cnt;

void merge(int st, int bp, int ed){
    int s1=st, e1=bp;
    int s2=bp+1, e2=ed;
    int p1=s1,p2=s2,p3=st;
    while(p1<=e1 && p2<=e2){

        while(p1<=e1 && A[p1]<=A[p2]){
            B[p3++]=A[p1++];
        }
        cnt+=p2-p3;
        B[p3++]=A[p2++];
    }
    if(p1<=e1){
        while(p1<=e1){
            B[p3++]=A[p1++];
        }
    }
    else if(p2<=e2){
        while(p2<=e1){
            B[p3++]=A[p2++];
        }
    }
    for(p1=st; p1<=ed; p1++)
        A[p1]=B[p1];
}

void mergeSort(int st,int ed){
    int bkp=(st+ed)/2;
    if(st<bkp) mergeSort(st,bkp);
    if(bkp+1<ed) mergeSort(bkp+1,ed);
    merge(st, bkp, ed);
}

int main()
{
    int i;
    while(scanf("%d",&N)!=EOF && N>0){
        for(i=0;i<N;i++) scanf("%d",A+i);
        cnt=0;
        mergeSort(0,N-1);
        printf("%I64d\n",cnt);

    }   
    return 0; 
}
