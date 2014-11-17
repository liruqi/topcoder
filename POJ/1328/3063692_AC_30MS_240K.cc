#include<stdio.h>
#include<math.h>
#include<algorithm>
#define mx 1000
struct node{
    int x,y;
    double rm;
}Isl[mx];
int n,d,i,j;
bool cmp(node p,node q){return p.rm<q.rm;}

bool cov[mx];
bool unr;
int sol(){
    int cnt=0;
    if(unr)return -1;
    memset(cov,0,sizeof(cov));
    for(i=0;i<n;i++)
        if(!cov[i]){
            double cur=Isl[i].rm;
            for(j=i;j<n;j++){
                double dx=Isl[j].x-cur;
                double dy=Isl[j].y;
                if(dx*dx+dy*dy<=d*d)
                    cov[j]=1;
            }
            cnt++;
        }
    return cnt;
}

int main(){
    int ks=0;
    while(scanf("%d%d",&n,&d), n||d){
        unr=false;
        for(i=0;i<n;i++){
            scanf("%d%d",&Isl[i].x,&Isl[i].y);
            if(Isl[i].y>d)unr=true;
            else Isl[i].rm=sqrt(d*d-Isl[i].y*Isl[i].y)+Isl[i].x;
        }
        std::sort(Isl,Isl+n,cmp);
        printf("Case %d: %d\n",++ks,sol());
    }
}
