#include <stdio.h>
#define min(x,y) (x)<(y)?(x):(y)
#define maxn 10001
int CL[maxn],ML,N,cnt;
int main(){
    int i,j;
    while(~scanf("%d%d",&N,&ML)){
        for(cnt=0,i=N;i;i--) scanf("%d",&j),CL[j]++;
        for(i=ML;i>=0;i--) while(CL[i]){
            CL[i]--;
            for(j=min(i,ML-i);j>=0;j--)if(CL[j]){CL[j]--;break;}
            cnt++;
        }
        printf("%d\n",cnt);
    }
}
