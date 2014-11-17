#include <stdio.h>
struct position{
	char *name;
	double speed;
	int w;
	int s;
}p[3]={
	{"Wide Receiver",4.5,150,200},
	{"Lineman",6.0,300,500},
	{"Quarterback",5.0,200,300}};
	
int main()
{
	int we,st,i;double sp;bool f;
	while(scanf("%lf %d %d",&sp,&we,&st) && we * st)
	{
		for(f=1,i=0;i<3;i++)
			if(sp <= p[i].speed && we >= p[i].w && st >= p[i].s)
			{
				printf("%s ",p[i].name);
				f=0;
			}
		if(f) printf("No positions");				
		printf("\n");
	}
	return 0;
}
