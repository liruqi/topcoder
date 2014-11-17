#include <stdio.h>
#include <list>
using namespace std;

#define maxn 1000
#define maxh 10000
int xa[maxn+1],ya[maxn+1];
list<int> ht[maxh];
typedef list<int>::iterator lii;

int hash(int p){
    int xsq=xa[p]*xa[p];
    int ysq=ya[p]*ya[p];
    return (xsq+ysq)%maxh;
}

bool query(int x, int y){
    xa[maxn]=x;
    ya[maxn]=y;
    int hp=hash(maxn), xp;
    for(lii it=ht[hp].begin(); it!=ht[hp].end(); ++it)
    {
        xp=*it;
        if(xa[xp]==x && ya[xp]==y)return 1;
    }
    return 0;
}

int main(){
    int n,i,j,cnt;
    while(~scanf("%d",&n) && n>0){
		for(i=0;i<maxh;i++) ht[i].clear();
        for(i=0;i<n;i++){
            scanf("%d%d",xa+i,ya+i);
            ht[hash(i)].push_back(i);
        }
        cnt=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)if(i!=j){
                int vx=ya[i]-ya[j];
                int vy=xa[j]-xa[i];
                int nx=vx+xa[j];
                int ny=vy+ya[j];
                if(query(nx, ny) && query(nx-vy, ny+vx))
                {
					//printf("(%d-%d) -> (%d-%d) @@@ ",xa[i],ya[i],xa[j],ya[j]);
					//printf("(%d-%d) -> (%d-%d)\n",nx, ny,nx-vx, ny-vy);
                    cnt++;
                }
            }
        printf("%d\n",cnt>>2);
    }
    
}
