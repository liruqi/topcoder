#include <stdio.h>
#include <math.h>


int gcd (int a, int b){
    int r;
    while(a%b){
		r=a%b;
 		a=b;
		b=r;
    }
    return b;
}

int A[51];

int main()
{
	
	int i,j,n;

	while( scanf("%d",&n)==1 && n )
	{
		int cnt=0;
		int tot=n*(n-1)/2;
		for(i=1; i<=n; i++)
			scanf("%d",A+i);
		for(i=1; i<n; i++)
			for(j=i+1; j<=n; j++)
				if( gcd(A[i],A[j])==1 )
					cnt++;
		//printf("%d\n",cnt);
		if(cnt==0)
			puts("No estimate for this data set.");
		else 
			printf("%.6lf\n",sqrt( (double)(6*tot)/cnt) );
	}
	return 0;
}
