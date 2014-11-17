main(m,n,c,r){
while(~scanf("%d%d%d",&m,&n,&c)&&n)
m-=7,n-=7,printf("%d\n",m*n/2+((m*n)&1)*c);
}
