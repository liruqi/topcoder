#include <math.h>
#include <stdio.h>
#include <string.h>
#define maxn 10001
int C[maxn],mr; //max radii

int findmaxpp(double mid){
    int cnt=0;
    for(int i=1;i<=mr;i++){
        double fn=(double)(i*i)/mid;
        int n=(int)fn;
        cnt+=n*C[i];
    }
    return cnt;
}
int main()
{
    int T,N,pp;
    long long tot=0;
    scanf("%d",&T);
    while(T-- && EOF!=scanf("%d%d",&N,&pp)){
        pp++;
        int radii,i;
        memset(C,0,maxn*4);
        for(mr=0,i=0;i<N;i++){
            scanf("%d",&radii);
            C[radii]++;
            tot+=radii*radii;
            if(radii>mr)
                mr=radii;
        }
        
        double up=(double)tot/pp, low=(double)(mr*mr)/pp, mid;
        while(up-low>1e-4){
            mid=(up+low)/2;
            if(findmaxpp(mid)>=pp)
                low=mid;
            else 
                up=mid;
        }
        mid=(up+low)/2;
        printf("%.4lf\n",mid*M_PI);
    }
    return 0;
}
/*
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2
*/
