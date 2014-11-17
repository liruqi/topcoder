int B(int n){return n&-n;}
main(I,n,i){while(scanf("%d",&I)&&I){n=0;for(i=(B(I)<<1);i & I; i <<= 1)n++; printf("%d\n",I + B(I) + (1<<n) -1);}}
