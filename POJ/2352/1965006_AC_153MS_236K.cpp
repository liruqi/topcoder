#include <iostream.h>
#define MS 65536	//1>>16
#define MaxN 32010

int A[MS];
int cnt[MaxN];

int min2(int n)
{
 	return n & (-n);
}

void Insert(int n)
{
 	 for(; n<MS; n+=min2(n))
 	 {
	  	 A[n]++;
     }
}

int Search(int n)
{
 	int r=0;	   
 	while(n>0)
 	{
	 	r+=A[n];
		n -= min2(n);
    }
	return r;
}

int main()
{
 	int i,n, x,y;

 	cin>>n;
 	
 	for(i=0; i<n; i++)
 	{
	 	cin>>x>>y;
	 	x++;
	    Insert(x);
		y = Search(x);
	  	cnt[y]++;
    }
    for(i=1; i<=n; i++)
    	cout<<cnt[i]<<endl;

   	return 0;
}
