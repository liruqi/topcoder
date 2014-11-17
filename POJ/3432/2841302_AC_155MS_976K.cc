/*
Problem: 1095
*/
#include <list>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define maxn 2100
#define maxh 87719
typedef list <pair<int,int> > lpi;
typedef lpi::iterator lii;
lpi ht[maxh];
int px[maxn],py[maxn];

int hash(int p){
    return (px[p]*px[p]+py[p]*py[p])%maxh;
}
int N;

bool exist(int x,int y){
    if(x&1) return false;
    if(y&1) return false;
    x>>=1; y>>=1;
    px[2007]=x; py[2007]=y;
    int hv=hash(2007);
    for(lii it=ht[hv].begin(); it!=ht[hv].end(); ++it)
        if(it->first==x && it->second==y)
            return true;
    return false;
}

int main()
{
	int N,i,j,x,y;
	scanf("%d",&N);
	for(i=0;i<N;i++){
        scanf("%d%d",px+i,py+i);
        int hv=hash(i);
        ht[hv].push_back(make_pair(px[i],py[i]));
    }
    int cnt=0;
    for(i=0;i<N;i++)
        for(j=i+1;j<N;j++){
            int mx=(px[i]+px[j]);
            int my=(py[i]+py[j]);
            int vx=-(py[i]-py[j]);
            int vy=(px[i]-px[j]);
            if(exist(mx+vx,my+vy) && exist(mx-vx,my-vy)) cnt++;
        }
    printf("%d",cnt>>1);
    
}
