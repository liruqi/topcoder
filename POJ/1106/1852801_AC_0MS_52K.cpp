#include <iostream.h>
#include <math.h>
#include <stdlib.h>

typedef struct dot{
	int x;
	int y;
	int n;
}Dot;

inline int max(int x,int y)
{
	return x>y?x:y;
}

int i,j,k,online;
Dot d[150];
int ox, oy, n, vn;
float r;
void main()
{
	while(cin>>ox>>oy>>r && r>=0)
	{
		cin>>n;
		for(vn=0,i=0;i<n;i++)
		{
			cin>>d[vn].x>>d[vn].y;
			d[vn].x -= ox;
			d[vn].y -= oy;
			if(d[vn].x * d[vn].x + d[vn].y * d[vn].y - r * r < 0.0000001)
			{
				vn++;
			}
		}

		for(i=0; i<vn ; i++)
		{
			d[i].n=0;
			online=1;
			for(j=0; j<vn; j++)
			{
				if(j==i)
					continue;
				if(d[i].x * d[j].y > d[i].y * d[j].x)
					d[i].n++;
				else if(d[i].x * d[j].y == d[i].y * d[j].x)
					online++;
			}
			d[i].n = max(d[i].n + online, vn - d[i].n);
		}
		for(ox=0,i=0; i<vn; i++)
				ox=max(ox,d[i].n);
		cout<<ox
			<<endl;
	}
}