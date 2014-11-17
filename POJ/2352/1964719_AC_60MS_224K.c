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

	 	x++; n=x;
		for(; n<MS; n += n & (-n))
	  	 	A[n]++;
        y=0; n=x;
        while(n>0)
 		{
		 	y+=A[n];
			n -= n & (-n);
    	}
	  	cnt[y]++;
    }
    for(i=1; i<=number; i++){
    	printf("%d\n",cnt[i]);
    }
    
   	return 0;
}

