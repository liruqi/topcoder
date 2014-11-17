#include <stdio.h>
#define MAX_SIZE 1025
#define LOW_BIT(x)  ((x) & (-x))

int size;
int cum [MAX_SIZE][MAX_SIZE];

int cumulative (int x, int y)
{
  	int res, ix;
  	res = 0;
  	x++; y++;
  	for(; y > 0; y -= LOW_BIT(y))
    for(ix = x; ix > 0; ix -= LOW_BIT(ix))
      	res += cum[ix-1][y-1];
  	return res;
}

void update (int a, int x, int y){
  	int ix;
  	x++; y++;
  	for(; y < (size+1); y += LOW_BIT(y))
    	for(ix = x; ix < (size+1); ix += LOW_BIT(ix))
			cum[ix-1][y-1] += a;
}

/* compute sum 0 < i < x, 0 < j < y */
int sum (int x1, int y1, int x2, int y2)
{
    int res=cumulative(x2, y2);
    res -= cumulative(x1-1, y2);
    res -= cumulative(x2, y1-1);
    res += cumulative(x1-1, y1-1);
  	return res;
}

int main()
{
  	int cmd, a1, a2, a3, a4;
  	do {
       	scanf ("%d", &cmd);
       	switch (cmd)
		{
		case 0:
		  	scanf ("%d", &size);
		  	size++;
	  		break;
		case 1:
	        scanf ("%d %d %d", &a1, &a2, &a3);
	  		update (a3, a1, a2);
	  		break;
		case 2:
	  		scanf ("%d %d %d %d", &a1, &a2, &a3, &a4);
	  		printf ("%d\n", sum(a1, a2, a3, a4));
	  		break;
		}
    } while(cmd != 3);
  	return 0;
}
