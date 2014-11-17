#include<string.h>
#include<stdio.h>
#define R 5
#define C 6
bool oin[R][C], p[R][C],in[R][C];
//original input data;	pressed button;	 input data
int i,j,k;
static int bound=1<<C;
char s[10];

bool judge_off(void)
{
	bool tmp=0;
	for(int i=0;i<C;i++)
		tmp = tmp || in[R-1][i];
	return !tmp;
}

void press(int i,int j)
{
	if(i-1 >= 0)
		in[i-1][j] = !in[i-1][j];
	if(i+1 < R) 
		in[i+1][j] = !in[i+1][j];
	if(j-1 >= 0)
		in[i][j-1] = !in[i][j-1];
	if(j+1 < C) 
		in[i][j+1] = !in[i][j+1];

	in[i][j] = !in[i][j];
	p[i][j]=1;
}

int main()
{
	int n,t;
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		
		for(i=0;i < R;i++)
			for(j=0; j < C; j++)
			{		
				p[i][j]=0;
				scanf("%d",&oin[i][j]);		
			}
		
		;
		for(k=0; k<bound; k++)
		{
			for(i=0;i < R;i++)
				for(j=0; j < C; j++)
				{
					p[i][j]=0;
					in[i][j]=oin[i][j];
				}
			for(j=0; j<C; j++)
			{	
				p[0][j]=(bool)((int)(k/(1<<j) )%2);
			}
			for(j=0;j<C;j++)
				if(p[0][j])
					press(0,j);
			//end of the first row of pressed line initilization	
			for(i=1; i<R; i++)
			{
				for(j=0; j<C; j++)	
					if(in[i-1][j])
						press(i,j);
			}
			//print result
			if(judge_off())
			{
				printf("PUZZLE #%d\n",t);
				for(i=0;i < R;i++)
				{
					for(j=0; j < C; j++)
						printf("%d ",p[i][j]);
					printf("\n");
				}
				break;
			}
		}
	}
	return 0;
}
