/*pku1922 Ride to School  051218*/
#include<stdio.h>
#define N 100
int main()
{
    int arr_time,last;
    int num;
    int ii,jj,kk;
    int speed;
    float tmp;
    while(scanf("%d",&num) && num)
    {
        for(ii=0,last=10000;ii<num;ii++)
        {
            scanf("%d%d",&speed,&kk);
            if(kk>=0)
            {
                tmp=3600*4.5/speed+kk;
				if(tmp-(int)tmp<.001)
                    arr_time=(int)tmp;
                else
                    arr_time=1+(int )tmp;
                last = ( arr_time<last)?arr_time:last;     
			}
        }
        printf("%d\n",last);
    }
	return 0;
}
