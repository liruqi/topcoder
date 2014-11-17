#define lowBit(x) (x&(-x)) 
main(){
int t,x;
scanf("%d",&t);
while(t--){
scanf("%d",&x);
printf("%d %d\n",x-lowBit(x)+1,x+lowBit(x)-1);
}
}
