int a,b,c,d;
int reduc(){
    if(d>2)return 1;
    if(d<2)return 0;
    scanf("%d%d%d",&a,&b,&c);
    return b*b>=4*a*c;
}
main(){
    scanf("%d",&d);
    puts(reduc()?"NO":"YES");
}
