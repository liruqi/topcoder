#include <stdio.h>
#define MS 1000040
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
  
//  for(i=2;i<MS/100;i++)
//     if(prime[i]) printf("%d\t",i);
  int a,d,n;
  scanf("%d%d%d",&a,&d,&n);
  while(a>0 && d>0 && n>0)
  {
      
      for(j=0,k=0; k<n; j++)
      {
          if(prime[a + j*d])
			  k++;
      }
      j--;
      i = a + j * d;
      printf("%d\n", i);
      scanf("%d%d%d",&a,&d,&n);
  }
  
  return(0);
}
