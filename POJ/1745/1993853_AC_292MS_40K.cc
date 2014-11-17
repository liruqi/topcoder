#include <stdio.h>
bool r[100], f1[100], f2[100];
int N,K;
int main() {
	int i,j,t,k;
	scanf("%d%d", &N, &K);
	scanf("%d", &t);
	t%=K;
	t=(t+K)%K;
	r[t]=1;
	for(i=1; i<N; i++) {
	 	scanf("%d", &t);
	 	t%=K;
	 	t=(t+K)%K;
	 	k=K-t;
	 	if(t>0) for(j=0; j<K; j++) {
			f1[(j+t)%K]=r[j];
			f2[(j+k)%K]=r[j];
		}
		for(j=0; j<K; j++) {
			r[j] = f1[j] | f2[j];
		}
    }
    if(r[0]) puts("Divisible");
 	else puts("Not divisible");
 	
 	scanf("%d", &t);
	return 0;
}
