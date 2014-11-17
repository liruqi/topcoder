//PKU 1988
#include <stdio.h>
#define MaxN 30001
int A[MaxN];
int UP[MaxN],LOW[MaxN];

int Root(int n){
	int m=n, length=0;
	while(A[m]){ 
        length+=UP[m]+1;
        m=A[m];
        
	}
	if(length) {
		A[n]=m;
		UP[n]=length-1;
	}
	return m;
}

int Count(int oper){
	int r=0;
	while(A[oper]){
		r+=UP[oper]+1; 
		oper=A[oper];
	}
	return r;
}

void Move(int oper, int des){
	oper=Root(oper);
	des=Root(des);
	A[oper]=des;
	UP[oper]=LOW[des];
	LOW[des]+=(LOW[oper]+1);
}

int main()
{
 	int tst, x, y;
 	char cmd[3];
 	scanf("%d",&tst);
 	while(tst-->0)
	{
	 	scanf("%s",cmd);
        switch(cmd[0])
		{
		 	case 'M':
				scanf("%d%d",&x,&y);
				Move(x,y);
				break;
			case 'C':
				scanf("%d",&x);
				printf("%d\n",Count(x));
				break;
			default:
				return 0;
		}
	}
	
	return 0;
}
