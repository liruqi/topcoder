#include<stdio.h>
void main()
{
	int n1,n2,n3,n4,n5,n6,num;
	scanf("%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6);
	while(n1!=0||n2!=0||n3!=0||n4!=0||n5!=0||n6!=0)
	{
		num=n4+n5+n6;	//initialize
		int c1=0,c2=0,c3=0;
		if(n3%4==0)		//n3 can be devided by 4
		{
			num+=n3/4;
		}
		else{
			num+=n3/4+1;
			c3=4 - n3%4;
		}
		if(c3)
		{
			c2=2*c3-1;
			c1=9*c3-4*c2;
		}
		c2+=5*n4;
		c1+=11*n5;
		while(!(c2>=n2 && c1+4*c2>=n1+4*n2))
		{
			c2+=9;
			num++;
		}
		printf("%d\n",num);
		scanf("%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6);
	}
}
