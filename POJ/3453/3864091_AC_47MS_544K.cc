#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


using namespace std;

template<class T>
void show(T x){ cout<< "# "<< x <<endl; }
template<class T>
void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef VI::iterator VII;
typedef VS::iterator VSI;


#define EPS 1e-9
#define PI_2 (M_PI*2.0)
#define INF 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))

char buf[81][81*4];

struct teamADT{
	string name,full;
	int play;
	int win;
	int lose;
	int tie;
	int w_sc;
	int l_sc;
	teamADT():play(0),win(0),lose(0),tie(0),w_sc(0),l_sc(0){}
	int getPoint(){return win*3+tie;}
} ;
map<string,int> id;
bool operator<(teamADT p,teamADT q)
{
	//cout<<p.name<<" "<<q.name<<endl;
	if(p.getPoint() != q.getPoint())
		return p.getPoint() < q.getPoint();
	int d1=p.w_sc - p.l_sc;
	int d2=q.w_sc - q.l_sc;
	if(d1!=d2)
		return d1<d2;
	if(p.w_sc != q.w_sc)
		return (p.w_sc < q.w_sc);
	if(p.win != q.win)
		return p.win < q.win;
	return id[string(p.name)] < id[string(q.name)];
}

string D2S(int x)
{
	stringstream ss;
	ss<<x;
	return ss.str();
}

int main()
{
	int team_n;
	int match_n;
	while(1)
	{
		teamADT team[81];
		cin>>team_n;
		if(!team_n) break;
		VS names, lead3;
		int colA=0;
		for(int i=0;i<team_n;i++)
		{
			cin>>team[i].name;
			string str(team[i].name);
			names.push_back(str);
			id[str] = i;
			colA >?= str.size();
			if(str.size() > 3)
				str = str.substr(0,3);
			while(str.size() < 3)
				str += " ";
			lead3.push_back(str);
		}
		
		for(int i=team_n-1;i>=0;i--)
		{
			team[i].full = team[i].name;
			while(team[i].full.size() < colA)
				team[i].full += " ";
		}
		
		string line="+"; //+------+---+---+
		for(int i=colA;i;i--) line+="-";
		line += "+";
		for(int i=team_n;i;i--) line+="---+";
		for(int r=0;r<team_n;r++)
		{
			for(int c=0;c<(team_n);c++)
			{
				buf[r][c*4] = ' ';
				buf[r][c*4+1] = ' ';
				buf[r][c*4+2] = ' ';
				buf[r][c*4+3] = '|';
				if(r == c)
				{
					buf[r][c*4+1] = 'X';
				}
			}
			buf[r][4*team_n] = 0;
		}
		cin>>match_n;
		string na1,na2,str;
		int id1,id2;
		
		for(int i=0;i<match_n;i++)
		{
			cin>>na1>>str>>na2>>str;
			int sc1=str[0]-'0';
			int sc2=str[2]-'0';
			
			id1 = id[na1];
			id2 = id[na2];
			
			buf[id1][4*id2] = str[0];
			buf[id1][4*id2+1] = str[1];
			buf[id1][4*id2+2] = str[2];
			
			team[id1].play++;
			team[id2].play++;
			team[id1].w_sc+=sc1;
			team[id1].l_sc+=sc2;
			team[id2].w_sc+=sc2;
			team[id2].l_sc+=sc1;
			if(sc1 > sc2)
			{
				team[id1].win ++;
				team[id2].lose ++;
			}
			else if(sc1 < sc2)
			{
				team[id1].lose ++;
				team[id2].win ++;
			}
			else 
			{
				team[id1].tie ++;
				team[id2].tie ++;
			}
		}
		
		cout<<"RESULTS:\n";
		cout<<line<<endl;
		cout<<"|"; for(int i=colA;i;i--) cout<<" "; cout<<"|";
		for(int i=0;i<team_n;i++)
			cout<<lead3[i]<<"|";
		cout<<endl<<line<<endl;
		for(int r=0;r<team_n;r++)
		{
			cout<<"|"<<team[r].full<<"|";
			cout<<buf[r]<<endl;
			cout<<line<<endl;
		}
		cout<<endl<<"STANDINGS:"<<endl;
		cout<<"----------"<<endl;
		sort(team, team+team_n);
		reverse(team, team+team_n);
		int colB = colA;
		if(team_n<10)
			colA = 2;
		else 
			colA = 3;
		int colC=1;
		int colD=1;
		int colE=1;
		int colF=1;
		int colG=3;
		int colH=1;
		for(int i=0;i<team_n;i++)
		{
			colC >?= D2S(team[i].play).size();
			colD >?= D2S(team[i].win).size();
			colE >?= D2S(team[i].tie).size();
			colF >?= D2S(team[i].lose).size();
			colG >?= (D2S(team[i].w_sc)+":"+D2S(team[i].l_sc)).size();
			colH >?= D2S(team[i].getPoint()).size();
		}
		colA++;
		colB++;
		colC++;
		colD++;
		colE++;
		colF++;
		colG++;
		colH++;
		//start index
		int stiA=0;
		int stiB=stiA+colA;
		int stiC=stiB+colB;
		int stiD=stiC+colC;
		int stiE=stiD+colD;
		int stiF=stiE+colE;
		int stiG=stiF+colF;
		int stiH=stiG+colG;
		int stiEOL = stiH+colH;
		
		memset(buf,' ',sizeof(buf));
		for(int i=0;i<team_n;i++)
		{
			string cs = D2S(i+1);
			int p;
			p = colA - 2 - cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			buf[i][colA-2] = '.';
			
			for(int c=0;c<team[i].name.size();c++)
				buf[i][stiB+c] = team[i].name[c];
			
			cs = D2S(team[i].play);
			p = stiD-1-cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			
			cs = D2S(team[i].win);
			p = stiE-1-cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			
			cs = D2S(team[i].tie);
			p = stiF-1-cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			
			cs = D2S(team[i].lose);
			p = stiG-1-cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			
			cs = (D2S(team[i].w_sc)+":"+D2S(team[i].l_sc));
			p = stiH-1-cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			
			cs = D2S(team[i].getPoint());
			p = stiEOL-1-cs.size();
			for(int c=0;c<cs.size();c++)
				buf[i][p+c] = cs[c];
			
			buf[i][stiEOL-1] = 0;
			cout<<buf[i]<<endl;
		}
		cout<<endl;
	}
}
/*
4
Slavia
Arsenal
Steaua
FCSevilla
4
Slavia - Arsenal 2:0
FCSevilla - Steaua 1:1
Steaua - Slavia 1:2
Arsenal - Slavia 0:0

*/
