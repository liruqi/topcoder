main()
{
int t;
int m,n;
int i;
scanf("%d",&t);
for(i=1; i <= t; i++)
{
 scanf("%d%d",&m,&n);
 printf("Scenario #%d:\n",i);
 m*=n;
 if(m%2) printf("%d.41",m);
 else printf("%d.00",m);
 printf("\n\n");
}
}

