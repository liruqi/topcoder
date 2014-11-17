/*
Problem: 1852
*/
#include <stdio.h>
#include <algorithm>
#define MAXN (1<<20)

using namespace std;

int L[MAXN],U[MAXN];

int main()
{
	int tc,len,pos,n,i;
	scanf("%d",&tc);
	while(tc--){
        scanf("%d%d",&len,&n);
        for(i=0;i<n;i++){
            scanf("%d",&pos);//cin>>pos;
            L[i]=min(pos,len-pos);
            U[i]=max(pos,len-pos);
        }
        printf("%d %d\n", *max_element(L,L+n),*max_element(U,U+n));
	}
	
	return 0;
}
