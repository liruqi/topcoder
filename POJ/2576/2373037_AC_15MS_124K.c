#include <stdio.h>
int A[30000];
int B[101];
int main(){ 
    int sum=0, hsum, hnum, N, i, j;
    scanf("%d", &N);
    for(i=1; i<=N; i++){
        scanf("%d", B+i);
        sum += B[i];
    }
    hnum = (N+1)/2;
    hsum = sum/2;
	i=1;
	while(B[i]>hsum) i++;
    A[B[i]]=1;
    for(i++; i<=N; i++){
        for(j=hsum-B[i]; j>=0; j--)
            if(A[j]&&(A[j]<hnum))
                A[j+B[i]]=A[j]+1;
    }
    i=hsum;
    while(!A[i]) i--;
    printf("%d %d", i, sum-i);
    scanf("%d", &N);
    return 0;
}