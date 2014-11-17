int N,K;
long long L[10000];

int enough(int x){
	int i;
	long long cnt=0;
	for(i=0;i<N;i++)
		cnt+=L[i]/x;
	return cnt>=K;
}

int main(){
	scanf("%d",&N);
	scanf("%d",&K);
	int i,ip,fp,up=0,low=0,mid;
	for(i=0;i<N;i++){
		scanf("%d.%d",&ip,&fp);
		L[i]=ip*100+fp;
		if(L[i]>up) up=L[i];
	}
	while(low<up){
		mid=(low+up+1)/2;
		if(enough(mid))low=mid;
		else up=mid-1;
	}
	char buf[20];
	sprintf(buf,"%d",low);
	int len=strlen(buf);
	if(len==1)
	{
		printf("0.0");
	}
	else if(len==2){
		printf("0");
	}
	for(i=0;i<len;i++){
		if(i==len-2){
			putchar('.');
		}
		putchar(buf[i]);
	}
	puts("");
}
