#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
struct itv{
int a,b;
}I[51000];

bool cmp(struct itv p,struct itv q){return p.a<q.a;}
int main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++) scanf("%d%d",&I[i].a,&I[i].b);
 sort(I,I+n,cmp);
 for(int i=0,j;i<n;i=j){
  for(j=i+1;j<n&&I[j].a<=I[i].b;j++)I[i].b>?=I[j].b;
  printf("%d %d\n",I[i].a,I[i].b);
 }
 return 0;
}