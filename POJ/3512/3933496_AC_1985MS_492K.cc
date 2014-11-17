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

#define EPS 1e-8
#define PI_2 (M_PI*2.0)
#define INF 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))
#define pb push_back
#define sqr(x) ((x)*(x))

/*
 * Problem : (pku) Incidental Points(Arab and North Africa 2007)
 * Author: liruqi
 * Algorithm: 排序 统计
 */

#define MAXSZ 1008
struct point
{
	int x,y;
};
bool operator < (point p,point q)
{
	return (ll)p.x * q.y > (ll)q.x * p.y;
}
bool operator == (point p,point q)
{
	return (ll)p.x * q.y == (ll)q.x * p.y;
}

point pa[MAXSZ], re[MAXSZ];
int pt_n;

char buf[96];
int nextpoint()
{
	gets(buf);
	if(buf[1]=='-') return 0;
	stringstream ss(buf);
	string str;
	ss>> pa[pt_n].x;
	ss>> pa[pt_n].y;
	pt_n++;
	return 1;
}

int res;

void solve(int base)
{
	int v_n=0;
	for(int p=base+1;p<pt_n;p++)
	{
		re[v_n].x = pa[p].x - pa[base].x;
		re[v_n].y = pa[p].y - pa[base].y;
		if(re[v_n].y < 0)
		{
			re[v_n].x = -re[v_n].x;
			re[v_n].y = -re[v_n].y;
		}
		if(re[v_n].y == 0)
		{
			if(re[v_n].x <0)
				re[v_n].x = -re[v_n].x;
		}
		v_n++;
	}
	sort(re,re+v_n);
	for(int p=0;p+res<v_n;)
	{
		int q=p;
		do
			q++;
		while(re[p] == re[q]);
		res >?= (q-p)+1;
		p=q;
	}
}

int main()
{
	int ks=1;
	while(1)
	{
		pt_n = 0;
		while( nextpoint() );
		if(!pt_n)
			break;
		res = 2;
		for(int base=0;base<pt_n;base++)
		{
			solve(base);
		}
		cout<<ks<<". "<<res<<endl;
		ks++;
	}
}


