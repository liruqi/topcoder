//team1 lexpegzmmdrp
#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxn 100
double arrT[maxn+1], tmpT[maxn+1];
int chkp[maxn+1];
int r,n;
double b,v,e,f;
double segTime(int x){
    double s=(x>=r? e*(double)(x-r):f*(double)(r-x));
    return 1/(v-s);
}

void
solve(){
    int i,j,k;
    for(i=0;i<n;i++){
        int st=chkp[i];
        if(i) tmpT[i]=arrT[i]+b;
        for(j=i+1; j<=n; j++)
        {
            double sum=0;
            for(k=chkp[j-1];k<chkp[j];k++)
                sum+=segTime(k-st);
            tmpT[j]=tmpT[j-1]+sum;
        }
        if(i==0){
            for(j=i+1; j<=n; j++)
                arrT[j]=tmpT[j];
        }
        for(j=i+1; j<=n; j++)
            arrT[j]=min(arrT[j], tmpT[j]);
    }
    printf("%lf\n", arrT[n]);
}

int main(){
    int i;
    while(~scanf("%d",&n) && n>0){
        for(i=1;i<=n;i++)
            scanf("%d",chkp+i);
        scanf("%lf",&b);
        scanf("%d%lf%lf%lf",&r,&v,&e,&f);
        for(i=0;i<=n;i++){
            arrT[i]=0;tmpT[i]=0;
        }
        solve();
    }
}