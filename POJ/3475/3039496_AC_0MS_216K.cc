#include<stdio.h>
typedef unsigned int uint;

uint ea,eb,res;
void s(uint ta,uint tb){
int ret=0;
for(;ta>ea;ta=(ta+1)/2)ret++;
for(;tb>eb;tb=(tb+1)/2)ret++;
res<?=ret;
}

int main(){
	uint c,d;
	while(~scanf("%d%d%d%d",&ea,&eb,&c,&d)){res=100;s(c,d);s(d,c);printf("%d\n",res);}
}
