#include <stdio.h>
#include <string.h>
#define min(x, y) ((x)<(y)?(x):(y))
#define maxs 2000
char vst[maxs];
int sttN, junN;

int stk[maxs],top;

int G[maxs][2];
int C[50];
int noEp(){//no Euler path
    int i;
    for(i=1;i<=junN;i++)
        if(C[i]%2)
            return 1;
            return 0;
}

void Euler(int n){
    int i;
    for(i=sttN;i>=1;i--)
        if(!vst[i]&&(G[i][0]==n||G[i][1]==n)){
            vst[i]=1;
            Euler(G[i][0]+G[i][1]-n);
            stk[top++]=i;
        }
}
void opt(){
    int i;
    for(i=0;i<top;i++){
        printf("%d",stk[i]);
        printf(i+1==top?"\n":" ");
    }
}
int main()
{
    int x,y,z;
    scanf("%d%d",&x,&y);
    while(x){
        int org=min(x,y);
        memset(vst, 0, maxs);
        memset(G, 0, 8*maxs);
        memset(C, 0, 200);
        top=0;sttN=1;junN=1;
        do{
            scanf("%d",&z);
            G[z][0]=x;
            G[z][1]=y;
            C[x]++;C[y]++;
            sttN++;
            junN>?=x;
            junN>?=y;
            scanf("%d%d",&x,&y);
        }while(x);
        //printf("junn = %d\n",junN);
        if(noEp())
        {
            puts("Round trip does not exist.");
        }
        else {
            Euler(org);
            opt();
        }
        scanf("%d%d",&x,&y);
    }
    return 0;
}
