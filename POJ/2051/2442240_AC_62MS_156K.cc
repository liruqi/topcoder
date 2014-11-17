#include <iostream>
using namespace std;

typedef struct{
    int q, p;
} reg;

bool cmp(reg r1,reg r2){
    return r1.q<r2.q;
}

reg R[1000];
int main()
{
    int cnt=0,K,i,j;
    char cmd[10];
    while(EOF!=scanf("%s",cmd)){
        if(cmd[0]=='#') break;
        scanf("%d%d",&R[cnt].q,&R[cnt].p);
        cnt++;
    }
    sort(R,R+cnt,cmp);
    
    scanf("%d",&K);
    for(i=1,j=1;i<=K;j++) {
        for(int k=0;k<cnt&&i<=K;k++) if(j%R[k].p==0)
        {
            printf("%d\n",R[k].q);
            i++;
        }
    }
    cin>>i;
}
