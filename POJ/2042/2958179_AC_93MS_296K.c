#define m 1<<15
int f[m];
main(n,i,j,k,l,s,t,u,v){
for(i=1;s=i*i,s<m;i++)for(j=0;t=j*j+s,j<=i&&t<=m;j++)for(k=0;u=k*k+t, k<=j&&u<m;k++)for(l=0;v=l*l+u,l<=k&&v<m;l++)f[v]++;while(scanf("%d",&n),n)printf("%d\n",f[n]);
}