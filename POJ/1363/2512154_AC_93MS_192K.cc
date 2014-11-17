#include<stdio.h>
#define maxn 1001
int stk[maxn],stop;
int per[maxn],ptop;
int N;
void
solve(){
    int dtop=N;
    for(stop=1, ptop=N, stk[0]=-1;ptop;){
        stk[stop++] = per[ptop--];

        while(stk[stop-1]==dtop){
            stop--;
            dtop--;
        }
    }
    puts(dtop?"No":"Yes");
}
int 
main()
{
    int i;
    while(~scanf("%d",&N) && N>0){
        while(1){
        scanf("%d",per+1);
        if(!per[1]) break;
        for(i=2;i<=N;i++) scanf("%d",per+i);
        solve();
        }puts("");
    }
    return 0;
}
