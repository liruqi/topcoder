#include <stdio.h>
#include <algorithm>
using namespace std;

int A[13], P[13], n, t, top;

int R[1000][13], C[1000], rn;

int solve(){
    int i,j,k;
    for(i=0;i<n;i++)
        scanf("%d",A+i);
    reverse(A,A+n);//nondecreasing
    rn=0;
    memset(R,0,1000*13*4);
    for(i=(1<<n)-1; i>0; i--){
        int sum=0;
        for(j=0; j<n; j++) if(i&(1<<j))
            sum+=A[j];

        if(sum == t){
            for(top=0,j=0;j<n;j++)
                if(i&(1<<j))
                    P[top++]=A[j];

			for(k=0;k<rn;k++) if(memcmp(R[k],P,top*4)==0) break;

            if(k==rn) {
            	memcpy(R[k], P, top*4);
            	C[k]=top;
            	rn++;
            }
            //printf("k=%d  top=%d\n",k,top);
        }
    }
    
	for(i=0;i<rn;i++)
		for(j=C[i]-1;j>=0;j--)
			printf(j?"%d+":"%d\n",R[i][j]);
}

int main()
{

    while(EOF!=scanf("%d%d",&t,&n)){
        if(!n) return 0;
        printf("Sums of %d:\n",t);
		solve();
        if(!rn)
        puts("NONE");
    }
}