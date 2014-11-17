#include <stdio.h>

int A[100001];
int main()
{
	int n,i;
	while(scanf("%d",&n) && n){
		for(i=1; i<=n; i++) scanf("%d",A+i);
		for(i=1; i<=n; i++)
			if(A[A[i]]!=i){
				puts("not ambiguous");
				break;
			}
		if(i==n+1) 
			puts("ambiguous");
	}
	return 0;
}
