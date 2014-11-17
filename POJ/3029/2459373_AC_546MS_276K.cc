// team1 lexpegzmmdrp
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int id;
    double x, y, v, a;
}guest;

guest G[10];
bool cmp(guest g1,guest g2){
    return g1.id<g2.id;
}
double gv;
int n;
double gettime()
{
    double gdx=0, gdy=0;    //guide position
    double curt=0, rett=0;
    for(int i=0;i<n;i++){
        double vx=G[i].v*cos(G[i].a), vy=G[i].v*sin(G[i].a);
        double x0=G[i].x+curt*vx-gdx, y0=G[i].y+curt*vy-gdy;
        double aa=G[i].v*G[i].v-gv*gv, bb=2*x0*vx+2*y0*vy, cc=x0*x0+y0*y0;
        bb/=aa;cc/=aa;
        double dd=bb/2;
        double ee=sqrt(dd*dd-cc);
        //ct=(bb+sqrt(bb*bb+aa*cc))/aa;     //catch time
        double ct=99999999;//sqrt(dd*dd-cc)-dd;
        if(ee-dd>-1e-9 && ee-dd<ct)
            ct=ee-dd;
        else 
            puts("error!");
        curt+=ct;           //current time
        gdx = G[i].x+vx*curt;
        gdy = G[i].y+vy*curt; //update guide position
        double dist=sqrt(gdx*gdx+gdy*gdy);
        double thistime=dist/G[i].v+curt;
        if(thistime>rett)
            rett=thistime;
    }
    return rett;
}

int main()
{
    scanf("%d",&n);
    while(n>0){
        int i,j=1;
        scanf("%lf",&gv);
        memset(G,0,10*sizeof(G[0]));
        for(i=0;i<n;i++) {
            scanf("%lf%lf%lf%lf",&G[i].x,&G[i].y,&G[i].v,&G[i].a);
            G[i].id=i;
        }
        double mt=999999;//min time
        do{
            double t=gettime();
            if(t<mt)
                mt=t;
        }while(next_permutation(G,G+n,cmp));
        printf("%.0f\n",mt);
        scanf("%d",&n);
    }
}
