#include <iostream.h>
int i;
typedef struct vertex{
	int x;
	int y;
	int next;
	double s;	//slope
}Ver;

class quadrant
{
	private:
		int head;
		int rear;
		int count;
		Ver Vt[50];
	public:
		quadrant(void);
		bool empty(void);
		void addver(int,int);
		void disp(void);
};

quadrant::quadrant(void)
{
	head=0;
	rear=0;
	count=0;
}
bool quadrant::empty(void)
{
	if(count)
		return 0;
	return 1;
}
void quadrant::addver(int x,int y)
{
	Vt[count].x=x;
	Vt[count].y=y;
	Vt[count].s=(double)y/x;
	
	if(!count)
	{
		Vt[count].next=-1;
	}
	//less than the smallest
	else if(Vt[count].s < Vt[head].s)
	{
		Vt[count].next=head;
		head=count;
	}
	//bigger than the biggest
	else if(Vt[count].s > Vt[rear].s)
	{
		Vt[rear].next=count;
		Vt[count].next=-1;
		rear = count;
	}
	else {
		int p=head;
		for(i=head;Vt[i].next>=0;i=Vt[i].next)
		{
			if(Vt[count].s < Vt[i].s)
				break;
			p=i;
		}
		Vt[p].next=count;
		Vt[count].next=i;
	}
	count++;
}

void quadrant::disp(void)
{
	if(count)
	{
		i=head;
		while(i>=0)
		{
		cout<<'('
			<<Vt[i].x
			<<','
			<<Vt[i].y
			<<')'
			<<endl;
		i=Vt[i].next;
		}
	}
}

int main()
{
	int x,y;
	quadrant q1,q2,q3,q4;
	cin>>x>>y;

	while(cin>>x>>y)
	{
		if(x>0)
		{
			if(y>0)
				q1.addver(x,y);
			else
				q4.addver(x,y);
		}
		else
		{
			if(y>0)
				q2.addver(x,y);
			else
				q3.addver(x,y);
		}
	}
	cout<<"(0,0)"<<endl;
	if(q1.empty())
	{
		q2.disp();
		q3.disp();
		q4.disp();
	}
	else if(q2.empty())
	{
		q3.disp();
		q4.disp();
		q1.disp();
	}
	else if(q3.empty())
	{
		q4.disp();
		q1.disp();
		q2.disp();
	}
	else if(q4.empty())
	{
		q1.disp();
		q2.disp();	
		q3.disp();
	}
	return 0;
}
