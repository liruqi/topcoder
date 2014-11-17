#include <stdio.h>
#include <string.h>

int C[100],n,k;

int divide(){
    int i,j=0;
    for(i=n/k;i;i--){
        while(!C[j]) j++;
        int st=j,ed;
        int tot=0,tl=0;
        for(;tot+C[j]<k;j++){
            tot+=C[j];
            tl +=j*C[j];    
        }
        ed=j;
        C[j]-=(k-tot);
        tl+=j*(k-tot);
        if(tl>(2+st)*k || tl<(ed-2)*k)
            return 0; 
    }
    return 1;
}

int main()
{
    int i,l,tc=1;
    char buf[100];
    while(scanf("%d%d",&n,&k)==2 && n){
        memset(C,0,400);
        for(i=0;i<n;i++){
            scanf("%s",buf);
            l=strlen(buf);
            C[l]++;
        }
        printf("Case %d: ",tc++);
        puts(divide()?"yes\n":"no\n");
    }
    return 0;
}
