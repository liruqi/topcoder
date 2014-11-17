#include <stdio.h>
int C,N,A[1001];
int main()
{
	int i,m,front=0,cnt=0,tc=1;
	while( scanf("%d%d",&C,&N) && C){
		cnt=0; front=0;
		for(i=C*N; i>0; i--) A[i]=0;
		for(i=0; i<N; i++) {
			scanf("%d",&m);
			A[m]=1;
		}

		for(i=C*N; i>0; i--){
			if(A[i]){		
				if(front>0)
					front--;
				else 
					cnt++;
			}
			else 
				front++;
		}
		printf("Case %d: %d\n",tc++, cnt);
	}
	return 0;
}