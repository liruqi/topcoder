main()
{
int tc,n;
scanf("%d",&tc);
while(tc-- && scanf("%d",&n)>0){
printf("%d\n",(n%2)?(n/2)*(n/2):(n/2)*(n/2-1));
}
}