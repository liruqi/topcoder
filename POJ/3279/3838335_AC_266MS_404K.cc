/*
Apollo
team4
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
const int inf = 182540340;

#define ni(x) (scanf("%d",&x))
#define ns(x) (scanf("%s",x))

int row, col;
int org[20][20];
int grid[20][20];

const int dir[][2] = {{-1,0},{0,0},{0,-1},{0,1},{1,0}};

#define chg(r,c) (grid[(r)][(c)]=!grid[(r)][(c)])

void flip(int r,int c)
{
	chg(r+dir[1][0],c+dir[1][1]);
	chg(r+dir[2][0],c+dir[2][1]);
	chg(r+dir[3][0],c+dir[3][1]);
	chg(r+dir[4][0],c+dir[4][1]);
}

int res;

int find(const int mask)
{
	int ret = 0;
	for(int r=1;r<=row;r++)
	{
		memcpy(grid[r],org[r],sizeof(org[0]));
	}
	for(int i=0;i<col;i++)
		if(mask & (1<<i))
		{
			flip(1,i+1);
			ret++;
		}
	for(int r=2;r<=row;r++)
	{
		for(int c=1;c<=col;c++)
			if(grid[r-1][c])
			{
				flip(r,c);
				ret ++;
				if(ret >= res)
					return inf;
			}
	}
	for(int c=1;c<=col;c++)
		if(grid[row][c])
			return inf;
	return ret;
}

void out(int mask)
{
	for(int r=1;r<=row;r++)
	{
		memcpy(grid[r],org[r],sizeof(org[0]));
	}
	for(int i=0;i<col;i++)
	{
		if(i)
			putchar(' ');
		if(mask & (1<<i))
		{
			flip(1,i+1);
			putchar('1');
		}
		else 
			putchar('0');
	}
	puts("");
	for(int r=2;r<=row;r++)
	{
		for(int c=1;c<=col;c++)
		{
			if(c>1)
				putchar(' ');
			if(grid[r-1][c])
			{
				flip(r,c);
				putchar('1');
			}
			else 
				putchar('0');
		}
		puts("");
	}
}

int main()
{
	while(ni(row) != -1)
	{
		//int stt=clock();
		ni(col);
		for(int r=1;r<=row;r++)
		{
			for(int c=1;c<=col;c++)
				ni(org[r][c]);
		}
		res = inf;
		int conf;
		for(int mask=0; mask<(1<<col); mask++)
		{
			int now = find(mask);
			if(now < res)
			{
				res = now;
				conf = mask;
			}
		}
		if(res == inf)
		{
			puts("IMPOSSIBLE");
		}
		else 
		{
			out(conf);
		}
		//cout<<clock()-stt<<" ms"<<endl; 
	}
}
