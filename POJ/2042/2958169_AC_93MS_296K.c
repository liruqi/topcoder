#define m 1<<15
int fsq[m];
main(n,i,j,k,l,s1,s2,s3,s4){
	for(i=1;s1=i*i,s1<m;i++){
		for(j=0;s2=j*j+s1, j<=i&&s2<=m;j++)
			for(k=0;s3=k*k+s2, k<=j&&s3<m;k++)
				for(l=0;s4=l*l+s3, l<=k&&s4<m;l++)
					fsq[s4]++;
	}
	while(scanf("%d",&n),n)	printf("%d\n",fsq[n]);
}
