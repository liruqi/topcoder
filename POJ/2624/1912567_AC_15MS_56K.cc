#include <stdio.h>
using namespace std;

int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4,vx,vy,ax,ay;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
    &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        if(x1==x3 && y1==y3)
        {
            vx=x2+x4;
            vy=y2+y4;
            ax=vx-x1;
            ay=vy-y1;                                                    
        }
        else if(x1==x4 && y1==y4)
        {
            vx=x2+x3;
            vy=y2+y3;
            ax=vx-x1;
            ay=vy-y1;                                
        }
        else if(x2==x4 && y2==y4)
        {
            vx=x1+x3;
            vy=y1+y3;
            ax=vx-x2;
            ay=vy-y2;
        }
        else{
            vx=x1+x4;
            vy=y1+y4;
            ax=vx-x2;
            ay=vy-y2;
        }
                                            
        printf("%.3f %.3f\n",ax,ay);
    }
    return 0;
}
