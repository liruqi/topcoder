#include <stdio.h>
#include <math.h>

int A[8][8], R[8][8];
int n;
void shr(int row){
    int tmp=A[row][n],i;
    for(i=n; i>1; i--)
		A[row][i]=A[row][i-1];
    A[row][1]=tmp;
}

int maxColSum(){
	int i,j,ans=0;
	for(i=1; i<=n; i++){
		int sum=0;
		for(j=1; j<=n; j++)
		    sum+=A[j][i];
		if(sum>ans)
			ans=sum;
	}
	return ans;
}

int main()
{
    int i,j,k, min_a;
    scanf("%d",&n);
    while(n>0){
		
	    for(i=1; i<=n; i++){
			for(j=1; j<=n; j++)
			scanf("%d",A[i]+j);
		}
		int max_n=ceil( pow(n,n) );
		int row, tmp;
		min_a=maxColSum();
		for(i=1; i<max_n; i++){
			j=i;
			row=n;
			
			while(j && j%n==0){
				row--;
				j/=n;
			}
			for(k=n; k>=row; k--){
				shr(k);
			}

			tmp=maxColSum();
			if(tmp < min_a)
			    min_a = tmp;
		}
		printf("%d\n", min_a);
		scanf("%d",&n);

	}
	return 0;
}
