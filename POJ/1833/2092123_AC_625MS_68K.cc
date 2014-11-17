#include <stdio.h> 
#include <algorithm> 
using namespace std; 

int A[1024]; 
int main() 
{ 
   int N, K, i;
   int tc; scanf("%d", &tc);
   while(tc-- && (scanf("%d %d", &N,&K)!=EOF) ){
   	   for(i=0; i<N; i++) scanf("%d", A+i);
   	   for(i=1; i<=K; i++) {
	   	    next_permutation(A, A + N);
	   }
	   
	   printf("%d", A[0]);
	   for (i = 1; i < N; i++) 
       printf(" %d", A[i]);
       printf("\n");
   }
   
   return 0; 
} 
