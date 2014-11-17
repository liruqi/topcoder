#include <iostream>
#include <stdlib.h>

using namespace std;
const int maxn = 50000;
struct mt{
	int x,y;
}M[maxn];
int N;
int cmp(const void *a, const void *b)
{
	int c=((struct mt *)a)->x;
	int d=((struct mt *)b)->x;
	if(c==d){
		c=((struct mt *)a)->y;
		d=((struct mt *)b)->y;
	}
	return c-d;
}

int main()
{
	int i,j;
	while(scanf("%d",&N)!=EOF && N)
	{
		for(i=0; i<N; i++)
			scanf("%d%d",&M[i].x, &M[i].y);
		qsort(M, N, sizeof(M[0]), cmp);
		int cnt=1; i--;
		while( i>=0 )
		{
			j=i;
			while(i>=0)
			{
				if(M[i].y>M[j].y)
					break;
				i--;
			}
			if(i>=0)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
