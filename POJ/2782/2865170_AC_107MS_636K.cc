//2782 Bin Packing
#include <stdio.h>
#define maxn 10001
int CL[maxn],ML,N,cnt,SL[maxn*10];
char Us[maxn*10];
int main(){
    int i,j;
    while(~scanf("%d%d",&N,&ML)){
        for(i=N;i;i--){
            scanf("%d",&j);
            CL[j]++;Us[i]=0;
        }cnt=0;
        for(i=0,j=1;i<maxn;i++)
            while(CL[i])
                SL[j++]=i,CL[i]--;
        for(i=N;i>0;i--) if(!Us[i]){
            Us[i]=1;
            int low=0,high=i-1,mid;
            while(low<high){
                mid = (low+high+1)/2;
                if(SL[mid]+SL[i]<=ML)
                    low=mid;
                else
                    high=mid-1;
            }
            j=low; while(j>0&&Us[j])j--; Us[j]=1;
            cnt++;
        }
        printf("%d\n",cnt);
    }
}
