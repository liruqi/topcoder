#include<stdio.h>
typedef unsigned int uint;
uint ea,eb,res,c,d,r;
void s(uint ta,uint tb){
for(r=0;ta>ea;ta=(ta+1)/2)r++;
for(;tb>eb;tb=(tb+1)/2)r++;
res<?=r;
}
int main(){
	while(~scanf("%d%d%d%d",&ea,&eb,&c,&d)){res=100;s(c,d);s(d,c);printf("%d\n",res);}
}