//2442
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int m,n;

int A[101][2001];

int solve(){
    int i,j,k;
    for(i=1;i<m;i++)
    {
    	priority_queue <int> sum;
    	for(j=0;j<n;j++)
    		for(k=0;k<n;k++)
    		{
    			int t=A[i-1][j]+A[i][k];
    			if(sum.size()<n)
    				sum.push(t);
    			else if(t<sum.top()){
    					sum.pop();
    					sum.push(t);
    			}
    			else
    				break;
    		}

    	for(j=n-1;j>=0;j--)
    		A[i][j]=sum.top(), sum.pop();
    }
    //for(j=n-1;j>=0;j--) printf(j?"%d ":"%d\n", A[m-1][j]);
    for(j=0;j<n;j++) printf(j+1==n?"%d\n":"%d ", A[m-1][j]);
}

int main()
{
	int T,i,j; scanf("%d",&T);
    while(T-->0 && EOF!=scanf("%d%d",&m,&n)){
        for(i=0;i<m;i++){
        	for(j=0;j<n;j++)
        		scanf("%d",A[i]+j);
        	sort(A[i],A[i]+n);
        }
        solve();
    }
}