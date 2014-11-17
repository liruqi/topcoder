
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    double x, y, v, alp;
}guest;

guest G[10];
int order[10];

double gv;
int n;
double gettime()
{
    double cx=0, cy=0;    //guide position
    double t=0, last=0;
    for(int i=0;i<n;i++){
        guest &g=G[order[i]];
        double vx=g.v*cos(g.alp), vy=g.v*sin(g.alp);
        double ex=g.x+t*vx-cx, ey=g.y+t*vy-cy;
        double a=g.v*g.v-gv*gv;
        double b=2*ex*vx+2*ey*vy;
        double c=ex*ex+ey*ey;
        b/=a;
        c/=a;
        double d=-b/2;
        double e=sqrt(d*d-c);
        double f=d+e;       //catch time
        t+=f;               //current time
        cx = g.x+vx*t;
        cy = g.y+vy*t;      //update guide position
        
        double thistime=sqrt(cx*cx+cy*cy)/g.v+t;
        if(thistime>last)
            last=thistime;
    }
    return last;
}

int main()
{
    scanf("%d",&n);
    while(n>0){
        int i,j=1;
        scanf("%lf",&gv);
        for(i=0;i<n;i++) {
            cin>>G[i].x>>G[i].y>>G[i].v>>G[i].alp;
            order[i]=i;
        }
        double best=999999;//min time
        do{
            double t=gettime();
            if(t<best)
                best=t;
            j++;
        }while(next_permutation(order,order+n));
        
        cout<<round(best)<<endl;
        scanf("%d",&n);
    }
    return 0;
}
