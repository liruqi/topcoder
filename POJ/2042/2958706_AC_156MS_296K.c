#define L(a,b,c,d) for(a=0;b=a*a+c,a<=d&&b<1<<15;a++)
int f[1<<15],i,j,k,l,s,t,u,v;
main(){L(i,s,0,i)L(j,t,s,i)L(k,u,t,j)L(l,v,u,k)f[v]++;for(;scanf("%d",&i),i;)printf("%d\n",f[i]);}