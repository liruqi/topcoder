#include <stdio.h>
const int maxn=1000001;
int A[maxn];

int N, S;
int main()
{
	int start, end, tot;
	int i, T;scanf("%d", &T);
	while(T-- && scanf("%d%d", &N, &S)!=EOF) {
		for(i=1; i<=N; i++) scanf("%d", A+i);
		start=1; end=1; tot=A[1];
		while(tot<S) {
			end++; 
			if(end>N) break; 
			tot+=A[end]; 
		}		//set initial distance
		if(end>=N && tot<S) {
			puts("0"); 
		}
		else {
			while(end<=N) {
				while(tot-A[start] >= S) {tot-=A[start]; start++;}
				start++, end++;
				while(end<=N)
				{
					tot-=A[start-1];
					tot+=A[end];
					if(tot-A[start] >= S) break;
					start++, end++;
				}
			}
			printf("%d\n",end-start+1, tot);
		}
	}
	return 0;
}
/*
input:
6 11
1 2 3 4 5 6
output:
2

i:
4 1
9 4 1000 1000
o:
1

*/