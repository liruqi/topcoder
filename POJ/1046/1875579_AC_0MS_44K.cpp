#include <iostream.h>
typedef struct c{
	int r;
	int g;
	int b;
	int ds;
}color;
color c[16];

int R,G,B,diss,ind,i;

int main()
{
	for(i=0;i<16;i++)
	{
		cin >>c[i].r
			>>c[i].g
			>>c[i].b;
	}
	while(cin>>R>>G>>B && R>=0)
	{
		ind=0;
		diss=(R-c[0].r)*(R-c[0].r)+(G-c[0].g)*(G-c[0].g)+(B-c[0].b)*(B-c[0].b);
		for(i=1;i<16;i++)
		{
			c[i].ds=(R-c[i].r)*(R-c[i].r)+(G-c[i].g)*(G-c[i].g)+(B-c[i].b)*(B-c[i].b);
			if(diss>c[i].ds)
			{
				diss=c[i].ds;
				ind=i;
			}
		}
		cout<<"("<<R<<","<<G<<","<<B<<") maps to ("
			<<c[ind].r<<","<<c[ind].g<<","<<c[ind].b<<")"
			<<endl;
	}
	return 0;
}