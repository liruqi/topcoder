#include <stdio.h>
#define MS 65536
#define MaxN 32010

int A[MS];
int cnt[MaxN];

int lowBit(int n)
{
 	return n & (-n);
}

void Insert(int n)
{
 	 if(!n) {
	 	 A[n]++;
     }
	 else for(; n<MS; n+=lowBit(n))
 	 {
	  	 A[n]++;
     }
}

int Search(int n)
{
 	int r=A[0];
 	while(n>0)
 	{
	 	r+=A[n];
		n -= lowBit(n);
    }
	return r;
}

int main()
{
 	int i,n, x,y;
 	
 	scanf("%d",&n);
 	
 	for(i=0; i<n; i++)
 	{
	 	scanf("%d%d",&x, &y);
		Insert(x);
		y = Search(x);
	  	cnt[y]++;
    }
    
    for(i=1; i<=n; i++)
    	printf("%d\n",cnt[i]);
   	scanf("%d",&n);
   	return 0;
}
