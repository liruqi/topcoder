#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1e-6
double x1[110],x2[110],y1[110],y2[110];

double xx[220], yy[220];
bool uz[220][220];
int n;


int main(){
	int ks=1;
	while(scanf("%d",&n), n){
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",x1+i,y1+i,x2+i,y2+i), 
            xx[i*2]=x1[i], xx[i*2+1]=x2[i],
            yy[i*2]=y1[i], yy[i*2+1]=y2[i];
		sort(xx,xx+2*n);
		sort(yy,yy+2*n);
		memset(uz,0,sizeof(uz));
		double res=0;
		for(i=0;i<n;i++){
            for(j=1;j<2*n;j++) if(x1[i]<=xx[j-1] && x2[i]>=xx[j])
            for(k=1;k<2*n;k++) if(y1[i]<=yy[k-1] && y2[i]>=yy[k])
            if(!uz[j][k]){
                uz[j][k]=1;
                res += (xx[j]-xx[j-1])*(yy[k]-yy[k-1]);
            }
        }
		
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",ks++,res);
	}
	return 0;
}

