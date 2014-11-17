#include<stdio.h>
#include<string.h>
#define pi 3.14159
int main()
{ 
  int X,Y,Z;
  double dis,alph;
  char s[20];
  while(scanf("%s",s) != EOF)
  { 
    if(strcmp(s,"ENDOFINPUT")==0) 
    	break;
    scanf("%d%d%d",&X,&Y,&Z);
    scanf("%s",s);
    if(Z>180) Z=360-Z;
    alph=(double)(Z*pi/180.0);
    dis=alph*(double)X*2.0;
    
    if(dis <= 5 * Y)
    {
    	double ans= (double)Y - dis/5.0;
    	printf("YES %d\n",(int)ans);
    }
    else
    {
    	printf("NO %d\n",5*Y);
    }
  }
  return 0;
}
