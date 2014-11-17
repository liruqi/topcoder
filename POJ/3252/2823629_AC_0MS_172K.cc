#include <stdio.h>

#define MAXN 40

int C[MAXN][MAXN];

int S[MAXN];

int N;

typedef unsigned int uint;


void init(){

    int i,j;

    for(i=0;i<MAXN;i++) 

        C[i][0]=C[i][i]=1;

    for(i=2;i<MAXN;i++)

        for(j=1;j<i;j++)

            C[i][j]=C[i-1][j-1]+C[i-1][j];

    for(i=2;i<MAXN;i++){

        S[i]=( 1<<(i-2) ) - (i&1)*C[i-1][(i-1)/2]/2;

        //printf("%d\n",S[i]);

    }

    //puts("");

}



//count round number from 1 to n

int rN(uint n){

    if(n<2) return 0;

    int i,cnt=0;
    uint j;

    for(i=1; (j=(1<<i))<=n; i++){

        cnt += S[i];

    }

    int tbl=i;//total bit len

    int tsb=1;//total set bit

    //printf("*tbl=%d, cnt:%d\n",tbl,cnt);

    for(i-=2; i>=0; i--)if((j=(1<<i))&n){

        for(j=0;j+tsb<=tbl/2;j++)

            cnt += C[i][j];

        tsb++;

    }

    if(tsb*2 <= tbl)

        cnt++;

    return cnt;

}



int main(){

    uint s,f;

    init();

    //while(~scanf("%d",&s)) printf("%d\n",rN(s));

    while(~scanf("%u%u",&s,&f))

        printf("%d\n",rN(f)-rN(s-1));

}
