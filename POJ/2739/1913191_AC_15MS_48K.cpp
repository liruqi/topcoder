#include <stdio.h>
#define MS 10040
bool prime[MS];

main()
{
  int i,j,k;
  prime[1]=0;
  for(i=2; i<MS; i++) 
	  prime[i] = 1;
  for(i=2;i<MS/2;i++)
  {
    if(prime[i])
    {
      for(j=i*2;j<MS;j=j+i) 
		  prime[j]=0;
    }
  }
  int n,cnt;
  scanf("%d",&n);
  while(n>0)
  {
      for(cnt=0, i=2; i<=n; i++) if(prime[i]) //i must be a prime
      {
          k=0;
          for(j=i;k<=n;j++)
          {
              k += prime[j]*j;
              if(k == n) 
              {
                   cnt++;
                   break;
              }
          }
      }
      printf("%d\n", cnt);
      scanf("%d",&n);
  }
  return 0;
}
