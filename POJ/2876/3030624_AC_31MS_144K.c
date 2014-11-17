s(p,v){if(p)if(p--,v)s(p,1),s(p,0),s(p,1);else s(p,0),s(p,0),s(p,0);else putchar(v?'-':' ');}
main(N){while(~scanf("%d",&N))s(N,1),puts("");}