prt(int n){if(n)n--,prt(n/26),putchar(n%26+'A');}
main(r,c){while(1+scanf("R%dC%d\n",&r,&c)&&r&&c)prt(c),printf("%d\n",r);}