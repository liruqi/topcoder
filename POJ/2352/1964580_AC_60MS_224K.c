#include <stdio.h>
#define MS 65536
#define MaxN 32010
int A[MS];
int cnt[MaxN];

int main()
{
 	int i,n;
 	int x,y;
 	int number;
 	scanf("%d",&number);
 	for(i=0; i<number; i++)
 	{
	 	scanf("%d%d",&x, &y);
	 	if(x==0) 
		{
		 	A[0]++;
		 	y = A[0];
		}
	 	else {
		 	n=x;
			for(; n<MS; n += n & (~n + 1))
		  	 	A[n]++;
	        y=0;
	        n=x;
	        while(n>0)
	 		{
			 	y+=A[n];
				n -= n & (~n + 1);
	    	}
	    	y+=A[0];
		}
	  	cnt[y]++;
    }
    for(i=1; i<=number; i++){
    	printf("%d\n",cnt[i]);
    }
    scanf("%d",&n);
   	return 0;
}

