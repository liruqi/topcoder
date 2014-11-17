#include <cstdio>
#include <algorithm>
using namespace std;

int H[10000];
int main()
{
    int R,C,tc=1;
    while(EOF!=scanf("%d%d",&R,&C) && R){
        int i,j,k=0;
        int cv,wv;  //water volume
        for(i=R;i;i--)
        for(j=C;j;j--)
            scanf("%d",H+k++);
        
        scanf("%d",&wv);
        sort(H,H+k);
        for(i=0,cv=0; i+1<k; i++)
        {
            if(cv+(i+1)*(H[i+1]-H[i])*100<wv)
                cv+=(i+1)*(H[i+1]-H[i])*100;
            else 
                break;
        }
        int remain=wv-cv;
        double hight=(double)H[i] + (double)remain/(100*(i+1));
        
        printf("Region %d\n",tc++);
        printf("Water level is %.2lf meters.\n",hight);
        printf("%.2lf percent of the region is under water.\n",
               (wv==0)?(double)0:(double)(i+1)*100.0/k);       
    }
    return 0;
}
