#include<stdio.h>
main()
{
 int b[100][100],m[100],p[100][100];
 int i,j,k,l,bmax,bmin,sump,t,n,tmin;
 double max;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
   bmax=0;bmin=32767;
   scanf("%d",&n);
   for(j=0;j<n;j++)
   {
      scanf("%d",&m[j]);
      for(k=0;k<m[j];k++)
      {
	     scanf("%d%d",&b[j][k],&p[j][k]);
	     if (bmax<b[j][k]) bmax=b[j][k];
	     if (bmin>b[j][k]) bmin=b[j][k];
       }
   }
   max=0.0;
   for(j=bmin;j<=bmax;j++)
   {
         sump=0;
         for(k=0;k<n;k++)
	      {
	      tmin=32767;
            for(l=0;l<m[k];l++)
	     if(b[k][l]>=j&&p[k][l]<tmin)
	           tmin=p[k][l];
	        sump+=tmin;
         }
         if((double)j/(double)sump>max)max=(double)j/(double)sump;
       }
    printf("%.3lf\n",max);
  }
} 
