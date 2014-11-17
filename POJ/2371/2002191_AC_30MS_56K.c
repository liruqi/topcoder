char A[5001];
void main()
{
 	int n,i,t,K;
 	scanf("%d",&n);
 	while(n--){
		scanf("%d",&i);
		A[i]++;
	}
	scanf("%*s%d",&n);
 	while(n--){
 		scanf("%d",&K);
 		for(i=1,t=0;t+A[i]<K;i++)
 			t+=A[i];
		printf("%d\n",i);
	}
}
