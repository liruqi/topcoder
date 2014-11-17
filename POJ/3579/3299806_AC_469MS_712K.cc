#include<stdio.h>
#include<algorithm>

typedef long long ll;
int A[110000];
int ls[110000],le[110000];
ll N,M;

int look(int x){
	int i,idx=1;
	for(i=0;i<N;i++){
		if(i>0 && A[i]==A[i-1]){
			ls[i]=ls[i-1]-1;
			le[i]=le[i-1]-1;
			continue;
		}
		while(idx<N && A[idx]-A[i]<x) 
			idx++;
		ls[i]=(idx-i-1);
		while(idx<N && A[idx]-A[i]==x)
			idx++;
		le[i]=(idx-i-1);
	}
	ll lss=0,les=0;
	for(i=0;i<N;i++)
		lss+=ls[i], les+=le[i];
	if(M>les) return -1;
	if(M<=lss) return 1;
	return 0;
}

int main(){
	int i;
	while(-1!=scanf("%I64d",&N)){
		for(i=0;i<N;i++)
			scanf("%d",A+i);
		M = (N*(N-1)/2+1)/2;
		std::sort(A,A+N);
		int lt=0,rt=A[N-1]-A[0],md;
		while(lt<rt){
			md=(lt+rt)/2;
			int sgn=look(md);
			if(sgn<0){
				lt=md+1;
			} else if(sgn>0) {
				rt=md;
			} else {
				printf("%d\n",md);
				break;
			}
		}
	}
}
