#include <stdio.h>
#include <math.h>
#include <string.h>
//110000
#define maxn 1000000
char A[maxn];
int S;

int obt_val(int n){
	int i,j;
	int sum=n*(n+1)/2-S;
	if(sum%2||sum<0) return 0;
	
	sum/=2;
	memset(A,0,sum+1);
	A[0]=1;
	for(i=1;i<=n;i++){
		for(j=sum-i;j>=0;j--){
			if(A[j]==1)
				A[j+i]=1;
		}
	}
	
	return A[sum];
}

int main()
{
	int i;
	scanf("%d",&S);
    for(i=sqrt(2*S)-1;!obt_val(i);i++);
	//for(i=sqrt(2*S)-1;printf("try %d\n",i),!obt_val(i);i++);
	printf("%d\n",i);
	scanf("%d",&S);
	return 0;
}
