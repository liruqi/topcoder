#include<iostream>
#define MS 100
using namespace std;

bool f[MS][MS];		//1->water
int M,N,i,j;
void trace(int i,int j)
{
	if(j-1>=0 && f[i][j-1] )
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
	int pond=0;
	char c;
	cin>>M>>N;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		{
			cin>>c;
			if(c=='W')
				f[i][j]=1;
			else
				f[i][j]=0;
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
	cout<<pond<<endl;
	return 0;
}