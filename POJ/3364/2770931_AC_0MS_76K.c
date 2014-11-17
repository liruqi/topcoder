int m,n,c,r;
main()
{
while(~scanf("%d%d%d",&m,&n,&c)&&n)
m-=7,n-=7,printf("%d\n",m*n/2+(m&1)*(n&1)*c);
}
