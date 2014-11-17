#define Max 1001
int P[Max], N, V[Max];

int gcd (int a, int b){
	int r;	

	while(a%b){
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
main(){
	int i=1,j,cnt,perm=1;
	scanf("%d",&N);
	while(i<=N) scanf("%d",P+i++);
	for(i=1; cnt=1,i<=N; i++) if(!V[i]) {
		for(j=P[i]; j!=i; j=P[j], cnt++) V[j]=1;
		perm=perm*cnt/gcd(perm, cnt);
	}
	printf("%d",perm);
}
