int euler(int n){
    int i,a=n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            a-=a/i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) a-=a/n;
    return a;
}

main()
{
int n;
while(scanf("%d",&n)==1){
if(!n) return;
printf("%d\n",euler(n));
}
}