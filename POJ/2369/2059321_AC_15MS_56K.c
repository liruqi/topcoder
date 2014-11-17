#define Max 1001
int P[Max], N, V[Max];
int gcd(int a, int b){ 
	return (a == 0) ? b : gcd(b % a, a);
}
int main(){
	int i,j,cnt,perm=1;
	scanf("%d",&N);
	for(i=1; i<=N; i++) scanf("%d",P+i);
	for(i=1; cnt=1,i<=N; i++) if(!V[i]) {
		for(j=P[i]; j!=i; j=P[j], cnt++)
			V[j]=1;
		perm=perm*cnt/gcd(perm, cnt);
	}
	printf("%d",perm);
	return 0;
}