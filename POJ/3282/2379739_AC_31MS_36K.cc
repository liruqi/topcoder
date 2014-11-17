#include <stdio.h>

int lque[100000],ltop,lcnt;
int rque[100000],rtop,rcnt;
char pos[10];
int main(){
    int T,M,i,cnt;
    int L,sum=0,lth;
    scanf("%d",&T);
    
    while(T--&&scanf("%d%d",&L,&M)!=EOF){
        ltop=rtop=0;
        for(i=0;i<M;i++){
            scanf("%d%s",&lth,pos);
            if(pos[0]=='l') 
                lque[ltop++]=lth;
            else
                rque[rtop++]=lth;
        }
        L*=100;
        for(sum=0,lcnt=1,i=0;i<ltop;i++){
            if(sum+lque[i]>L){
                lcnt++;
                sum=lque[i];
            }
            else 
                sum+=lque[i];
        }
        for(sum=0,rcnt=1,i=0;i<rtop;i++){
            if(sum+rque[i]>L){
                rcnt++;
                sum=rque[i];
            }
            else 
                sum+=rque[i];
        }
        //printf("left:%d right:%d\n",lcnt,rcnt);
        cnt=(lcnt>rcnt)?2*lcnt-1:2*rcnt;
        printf("%d\n",cnt);
        //cout<<cnt<<endl;
    }
    return 0;
}
