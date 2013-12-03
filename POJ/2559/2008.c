#include<stdio.h>
#include<string.h>
typedef long long ll;

int n;
ll stk[100000];
int pos[100000],top;

int main(){
    int i,t;
    while(scanf("%d",&n), n){
        ll ret=0,can;
        memset(pos,-1,sizeof(pos));
        top=1;
        scanf("%d",stk);
        pos[0]=0;
        for(i=1;i<n;i++){
            scanf("%d",&t);
            if(stk[top-1]<t){
                stk[top]=t;
                pos[top]=i;
                top++;
                continue;
            }
            while(top>0 && stk[top-1]>=t) {
                top--;
                can=stk[top]*(i-pos[top]);
                if(can>ret)
                    ret=can;
            }
            stk[top]=t;
            pos[top]=i;
            top++;
        }
        while(top>0) {
            top--;
            can=stk[top]*(i-pos[top]);
            if(can>ret)
                ret=can;
        }
        printf("%I64d\n",ret);
    }
}
