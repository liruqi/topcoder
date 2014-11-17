#include <iostream.h>
#include <stdlib.h>
int i,j;
int R,C;
int h[100][100], l[100][100];

int findmin(int i, int j)
{
	if(i-1 >= 0)
		if(h[i][j]>h[i-1][j])
			return 0;
	if(i+1 < R)
		if(h[i][j]>h[i+1][j])
			return 0;
	if(j-1 >= 0)
		if(h[i][j]>h[i][j-1])
			return 0;
	if(j+1 < C)
		if(h[i][j]>h[i][j+1])
			return 0;
	return 1;
}

inline int max(int i,int j)
{
	return (i>j)?i:j;
}

int findmax(void)
{
	int f=0;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			f=max(f,l[i][j]);
	return f;
}

void Adjust(int i,int j)
{
	if(i-1 >= 0)
		if(h[i][j] < h[i-1][j])
			if(l[i-1][j] < l[i][j]+1)
			{
				l[i-1][j] = l[i][j]+1;
				Adjust(i-1,j);
			}
	
	if(i+1 < R)
		if(h[i][j] < h[i+1][j])
			if(l[i+1][j] < l[i][j]+1)
			{
				l[i+1][j] = l[i][j]+1;
				Adjust(i+1,j);
			}
	
	if(j-1 >= 0)
		if(h[i][j] < h[i][j-1])
			if(l[i][j-1] < l[i][j]+1)
			{
				l[i][j-1] = l[i][j]+1;
				Adjust(i,j-1);
			}

	if(j+1 < C)
		if(h[i][j] < h[i][j+1])
			if(l[i][j+1] < l[i][j]+1)
			{
				l[i][j+1] = l[i][j]+1;
				Adjust(i,j+1);
			}
}

int main()
{
	cin>>R>>C;

	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
		{
			cin>>h[i][j];
			l[i][j]=0;
		}
/* find the local minimums
   time: O(n)	*/
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			l[i][j]=findmin(i,j);
	
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
		{
			if(l[i][j]==1)
				Adjust(i,j);	//time: O(n*n)
		}
	cout<<findmax();
	return 0;
}