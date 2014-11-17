int N,i,j,top,t;
long long cnt;
int stk[80000];
int main(){
	scanf("%d",&N);
	for(i=N;i;i--){
		int low=0,up=top,mid;scanf("%d",&t);
		while(low<up){
			mid=(low+up)/2;
			if(stk[mid]>t) low=mid+1;
			else up=mid;
		}
		j=low;
		cnt+=j;
		stk[j]=t;
		top=j+1;
	}
	printf("%I64d\n",cnt);
}