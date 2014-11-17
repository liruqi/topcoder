main(){
int n,i,x,r;while(~scanf("%d",&n)){r=0;for(i=n;i;i--)scanf("%d",&x),r=x^r;puts(r?"Yes":"No");}
}