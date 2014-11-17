int n,l,i,t,cnt[30000];
long long val[30000];
int main(){
	scanf("%d%d",&n,&l);
	memset(cnt,0,sizeof(cnt));
	for(i=0;i<n;i++)
		scanf("%d",&t), cnt[t%l]++;

	int sum=0;
	for(i=0;i<l;i++)
		sum+=cnt[i];
	
	for(i=0;i<l;i++)
		val[0]+=i*cnt[i];
	for(i=1;i<l;i++)
		val[i]=val[i-1]+sum-l*cnt[l-i];
	
	t=0;
	for(i=1;i<l;i++)
		if(val[t]>val[i])
			t=i;
	printf("%d\n",t);
}
