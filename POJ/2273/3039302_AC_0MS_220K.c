int r,c;
prt(int n){if(n)n--,prt(n/26),putchar(n%26+'A');}
sol(){prt(c);printf("%d\n",r);}
main(){
while(1+scanf("R%dC%d\n",&r,&c)&&r&&c)sol();
}
