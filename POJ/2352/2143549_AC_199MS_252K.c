int n,a[1<<15],c[1<<14];
main(i,x,t,p){scanf("%d",&n);for(i=0;i<n;i++){scanf("%d%*d",&x);x++;p=x;t=0;while(p)t+=a[p],p-=p&-p;while(x<32010)a[x]++,x+=x&-x;c[t]++;}for(i=0;i<n;i++)printf("%d\n",c[i]);}