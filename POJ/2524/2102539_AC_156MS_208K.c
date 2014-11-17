#include <stdio.h>
#include <string.h>
int A[50001];
int N;
int cnt;
int root(int n){
	int t=n;
	while(A[t]>0)
    	t=A[t];
	if(A[n]>0) 
	    A[n]=t;
	return t;
}

void unionSet(int x, int y)
{
 	A[x]=y;
 	cnt--;
}

int main(){
	int m, x, y, tc=1, r1, r2;
	while(scanf("%d%d", &N,&m) && N>0){
		memset(A, -1, 50001*4);
		cnt=N;
		while(m--){
			scanf("%d%d", &x,&y);
			r1=root(x);
			r2=root(y);
			if(r1!=r2)
			    unionSet(r1, r2);
	    }
	printf("Case %d: %d\n", tc++, cnt);
	}
	return 0;    
}
