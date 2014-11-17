#include<iostream>
#include<set>
using namespace std;


#define ni(x) (scanf("%d",&x))
#define ns(x) (scanf("%s", x))

int row,col,rob_n, ins_n;

struct robot{
	int r,c;
	char d[8];
	int position(){return (r<<16)+c;}
	int out()
	{
		return (r<=0 || r>row || c<=0 || c>col);
	}
} ;
robot ra[108];
set<int> pos;
int robid, repeat;
char action[8];
const string strdir="NESW";
const int intdir[][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};

int move()
{
	int pid=strdir.find( ra[robid].d[0] );
	if(action[0]=='L') pid=(pid+3*repeat) % 4;
	if(action[0]=='R') pid=(pid+repeat) % 4;
	if(action[0]!='F') {
		ra[robid].d[0]=strdir[pid];
		return 0;
	}
	while(repeat--)
	{
		pos.erase(ra[robid].position());
		ra[robid].r += intdir[pid][0];
		ra[robid].c += intdir[pid][1];
		//cout<<"* "<<ra[robid].r<<" "<<ra[robid].c<<endl;
		if(ra[robid].out()) 
		{
			cout<<"Robot "<<robid<<" crashes into the wall\n";
			return 1;
		}
		if(pos.find( ra[robid].position() ) != pos.end())
		{
			int i;
			for( i=0;i<rob_n;i++) 
				if(i!=robid && ra[i].position() == ra[robid].position()) 
					break;
			cout<<"Robot "<<robid<<" crashes into robot "<<i<<"\n";
			return 1;
		}
		pos.insert(ra[robid].position());
	}
	return 0;
}

int main()
{
	int ks;
	ni(ks);
	while(ks--)
	{
		pos.clear();
		ni(col);
		ni(row);
		ni(rob_n);
		ni(ins_n);
		int i;
		for(i=1;i<=rob_n;i++)
			ni(ra[i].c), ni(ra[i].r), ns(ra[i].d), pos.insert(ra[i].position());
		int crash = 0;
		for(i=ins_n;i>0;i--)
		{
			ni(robid);
			ns(action);
			ni(repeat);
			if(!crash)
				crash=move();
		}
		if(!crash)
			cout<<"OK\n";
	}
}
