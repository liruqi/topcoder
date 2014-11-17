#include <stdio.h>
int c[51];
bool r[100], f1[100], f2[100];
int N,K;
int main() {
	int i,j,t;
	scanf("%d%d", &N, &K);
	scanf("%d", &t);
	t%=K;
	t=(t+K)%K;
	if(2*t>K) t=K-t;
	r[t]=1;
	for(i=1; i<N; i++) {
	 	scanf("%d", &t);
	 	t%=K;
	 	t=(t+K)%K;
	 	if(2*t>K) t=K-t;
	 	c[t]++;
    }
	
    for(i=0; i<=K/2; i++) if(c[i]){
 		int k;
		for(j=0; j<K; j++) {			//f1 = r
			f1[j]=r[j];
		}
		for(j=1; 2*j<=c[i]; j++) {
			for(k=0; k<K; k++) {		//f2 = r >> 2*i*j
				f2[k] = r[(k+2*j*i)%K];	
			}
			for(k=0; k<K; k++) {		//f1 = f1 | f2
				f1[k] = f1[k] | f2[k];
			}
			for(k=0; k<K; k++) {		//f2 = r << 2*i*j
				f2[k] = r[(k+2*j*(K-i))%K];	
			}
			for(k=0; k<K; k++) {		//f1 = f1 | f2
				f1[k] = f1[k] | f2[k];
			}
		}
		for(j=0; j<K; j++) {			//f1 = r
			r[j]=f1[j];
		}
		if(c[i]%2) {					//if cnt is odd, once again
			t=i;
			k=K-t;
			for(j=0; j<K; j++) {
				f1[(j+t)%K]=r[j];
				f2[(j+k)%K]=r[j];
			}
			for(j=0; j<K; j++)
				r[j] = f1[j] | f2[j];	
		}
	}
    if(r[0]) puts("Divisible");
 	else puts("Not divisible");
 	scanf("%d", &t);
	return 0;
}
