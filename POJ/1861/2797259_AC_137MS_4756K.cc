
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

typedef list<int> lit;
typedef lit::iterator lii;


const int maxn = 1100000;
int A[maxn];
int N,M;

int root(int p){
    int r=p;
    while(A[r]>=0)
        r=A[r];
    if(r!=p) A[p]=r;
    return r;
}

typedef struct _node{
    int u,v,l;
}node;
node D[maxn];
int cmp(node p,node q){return p.l<q.l;}
int main()
{
    int i,j,cnt=0;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
	    scanf("%d%d%d",&D[i].u,&D[i].v,&D[i].l);
	}
	sort(D,D+M,cmp);
	memset(A,0xff,4*maxn);
    for(i=0;i<M;i++){
        int ur = root(D[i].u);
        int vr = root(D[i].v);
        //for(j=0;j<N;j++)printf("%d%c",A[j],j==N-1?'\n':' ');
        
        if(ur!=vr){
            A[ur]=vr;
            cnt++;
        }
        if(cnt==N-1){
            printf("%d\n",D[i].l);
            break;
        }
    }
    printf("%d\n",j=i+1);
    for(i=0;i<j;i++)
        printf("%d %d\n",D[i].u,D[i].v);
    return 0;
}