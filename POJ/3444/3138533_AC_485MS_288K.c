int main(){
	int i,n,ts[257],au[257];
	while(scanf("%d",&n), n){
		for(i=1;i<=n;i++) scanf("%d",ts+i);
		for(i=2;i<=n;i<<=1) {
			int j;
			for(j=1;j<=i/2;j++){
			au[2*j-1]=(ts[j]+ts[j+i/2])/2;
			au[2*j  ]=(ts[j]-ts[j+i/2])/2;
			}
			memcpy(ts,au,(i+1)*4);
		}
		for(i=1;i<=n;i++) printf("%d%c",ts[i],i==n?'\n':' ');
	}
}
