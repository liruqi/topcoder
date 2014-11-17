#include <stdio.h>

#define MAXN 40

int C[MAXN][MAXN],S[MAXN],N;

typedef unsigned int uint;


void init(){

    int i,j;

    for(i=0;i<MAXN;i++) 

        C[i][0]=C[i][i]=1;

    for(i=2;i<MAXN;i++)

        for(j=1;j<i;j++)

            C[i][j]=C[i-1][j-1]+C[i-1][j];

    for(i=2;i<MAXN;i++)

        S[i]=( 1<<(i-2) ) - (i&1)*C[i-1][(i-1)/2]/2;

}




int rN(uint n){

    if(n<2) return 0;

    int i,cnt=0;
    uint j;

    for(i=1; (j=(1<<i))<=n; i++){

        cnt += S[i];

    }

    int tbl=i;

    int tsb=1;

    for(i-=2; i>=0; i--)if((j=(1<<i))&n){

        for(j=0;j+tsb<=tbl/2;j++)

            cnt += C[i][j];

        tsb++;

    }

    if(tsb*2 <= tbl) cnt++;

    return cnt;

}



int main(){

    uint s,f;

    init();

    scanf("%u%u",&s,&f);

    printf("%d\n",rN(f)-rN(s-1));

}
