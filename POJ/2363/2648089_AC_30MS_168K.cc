#include <stdio.h>

int findArea(int a, int b, int c){
	return a*(b+c) + b*c;
}

int main(){

int C,N,a,b,c,th;scanf("%d",&C);
while(C-- && ~scanf("%d",&N)){
	
	int minArea=N<<8;
	for(a=1;a<=N;a++)if(N%a==0)
	for(b=a;b<=N;b++)if(N/a%b==0)
	{
		
		c=N/a;c/=b;
		minArea<?=findArea(a,b,c);
	}
	printf("%d\n",minArea<<1);
}

return 0;
}
