#include <iostream.h>
#include <string.h>
#include <math.h>

const int Max=300;
int N, ex, ey, sx,sy, cnt=0;
struct point{
	int x, y;
}A[Max*Max];
int top, bot;
void push(int x, int y){
	top++;
	A[top].x=x;
	A[top].y=y;
}
bool valid(int x, int y)
{	
	if((x>=0 && x<N) && (y>=0 && y<N))
			return true;
	return false;
}

void bfs()
{
	int last;
	top=bot=1;
	A[1].x=sx, A[1].y=sy;
	while(last=top)
	{
		for(int i=bot; i<=last; i++)
		{
			if(A[i].x==ex && A[i].y==ey) return;

			if(valid(A[i].x+1, A[i].y+2)) push(A[i].x+1, A[i].y+2);
			if(valid(A[i].x+1, A[i].y-2)) push(A[i].x+1, A[i].y-2);
			if(valid(A[i].x-1, A[i].y+2)) push(A[i].x-1, A[i].y+2);
			if(valid(A[i].x-1, A[i].y-2)) push(A[i].x-1, A[i].y-2);

			if(valid(A[i].x+2, A[i].y+1)) push(A[i].x+2, A[i].y+1);
			if(valid(A[i].x+2, A[i].y-1)) push(A[i].x+2, A[i].y-1);
			if(valid(A[i].x-2, A[i].y+1)) push(A[i].x-2, A[i].y+1);
			if(valid(A[i].x-2, A[i].y-1)) push(A[i].x-2, A[i].y-1);
		}
		bot=last+1;
		cnt++;
	}
}

void main(){
	int tc;
	cin>>tc;
	while(tc-- && cin>>N)
	{
		cnt=0;
		cin>>sx>>sy>>ex>>ey;
		while(abs(ex-sx)+abs(ey-sy)>7)
		{
			if(abs(ex-sx)*abs(ey-sy) == 0)
			{
				if(ex-sx) sx+=4*(ex-sx)/abs(ex-sx);
				if(ey-sy) sy+=4*(ey-sy)/abs(ey-sy);
				cnt+=2;
			}
			else{
				if(abs(ex-sx) > abs(ey-sy)) {
					sx+=2*(ex-sx)/abs(ex-sx);
					sy+=(ey-sy)/abs(ey-sy);
				}
				else{
					sx+=(ex-sx)/abs(ex-sx);
					sy+=2*(ey-sy)/abs(ey-sy);
				}
				cnt++;
			}
		}bfs();
		cout<<cnt<<endl;
	}
}
