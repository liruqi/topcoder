#include<stdio.h>
#include<string.h>
#define MS 100
char st[MS];
bool f[MS][MS];	
int M,N;

void trace(int i,int j)
{
	if(j-1>=0 && f[i][j-1])
	{
		f[i][j-1]=0;
		trace(i,j-1);
	}
	if(j+1<N && f[i][j+1])
	{
		f[i][j+1]=0;		
		trace(i,j+1);
	}
	if(i-1>=0)
	{
		if(f[i-1][j])
		{
			f[i-1][j]=0;
			trace(i-1,j);
		}
		if(j-1>=0 && f[i-1][j-1])
		{ 
			f[i-1][j-1]=0;
			trace(i-1,j-1);
		}
		if(j+1<N && f[i-1][j+1])
		{
			f[i-1][j+1]=0;
			trace(i-1,j+1);
		}
	}
	if(i+1<M)
	{
		if(f[i+1][j])
		{
			f[i+1][j]=0;
			trace(i+1,j);
		}
		if(j-1>=0 && f[i+1][j-1] )
		{
			f[i+1][j-1]=0;
			trace(i+1,j-1);
		}
		if(j+1<N && f[i+1][j+1])
		{
			f[i+1][j+1]=0;
			trace(i+1,j+1);
		}
	}
}

int main()
{
	int pond,i,j;
	char c;
	while(scanf("%d %d",&M,&N)!=EOF && (M+N!=0))
	{
	pond=0;
	for(i=0;i<M;i++)
	{
		scanf("%s",st);
		for(j=0;j<N;j++)
		{			
			if(st[j]=='@')
				f[i][j]=1;
			else
				f[i][j]=0;
		}
	}
	for(i=0; i<M; i++)
		for(j=0; j<N ; j++)
		{
			if(f[i][j])
			{
				f[i][j]=0;
				trace(i,j);
				pond++;
			}
		}
	printf("%d\n",pond);
	}
	return 0;
}
