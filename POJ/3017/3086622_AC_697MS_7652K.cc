#include<stdio.h>
#define mx 110000
#define inf 0x0f0f0f0f
typedef long long llg;

int A[mx],N,cmx;
llg stk[mx], sum[mx],M;
int idx[mx], top;
int D[20][mx];
#define max(a,b) ((a)>(b)?(a):(b))

void init_rmq(){
    int i,j,k;
    for(i=0;i<N;i++)
        D[0][i]=A[i+1];
    for(j=1,k=2; k<=N; j++,k<<=1)
        for(i=0;i+k<=N;i++)
            D[j][i] = max(D[j-1][i], D[j-1][i+k/2]);
}

int rmq(int b,int e){//interval [b,e]
    b--;
    int len=e-b;
    int j=31 - __builtin_clz(len);
    int k=(1<<j);
    return max(D[j][b],D[j][e-k]);
}

int main()
{
    int i,j;
    scanf("%d%I64d",&N,&M);
    for(i=1;i<=N;i++) {
        scanf("%d",A+i);
        if(A[i]>M){
            puts("-1");
            return 0;
        }
        sum[i]=sum[i-1]+A[i];
    }
    init_rmq();
    top=1;
    for(i=1;i<=N;i++) {
        llg can, cur=inf;
        for(j=top-1;j>=0;j--){
            if(sum[i] - sum[idx[j]] > M)
                break;
            can = stk[j] + rmq(idx[j]+1, i);
            //printf("max[%d, %d] = %d\n",idx[j]+1, i, rmq(idx[j]+1, i)); 
            if(can < cur)
                cur = can;
        }
        if(cur > stk[top-1]){
            stk[top]=cur;
            idx[top]=i;
            top++;
        }
        else idx[top-1]=i;
    }
    printf("%I64d\n", stk[top-1]);
}
