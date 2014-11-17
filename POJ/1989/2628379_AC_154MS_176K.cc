#include <stdio.h>
#include <string.h>

char U[10001];
int main(){
    int n,k,t,lss=1,cnt=0;
    scanf("%d%d",&n,&k);//cin>>n>>k;
    while(n--){
        scanf("%d",&t);
        if(!U[t]){
            U[t]=1,cnt++;
            if(cnt==k)
            {
                cnt=0;
                lss++;
                memset(U,0,k+1);
            }
        }
        
    }
    printf("%d\n",lss);//cout<<lss<<endl;
    scanf("%d",&t);
}
