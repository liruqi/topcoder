#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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


#define eps 1e-9
#define PI_2 (M_PI*2.0)
#define inf 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))
#define pb push_back

int dist[50008], rock, end, remv;

/*
 * return val: at least remove how many rocks to have the shortest distance 
 * greater or euqal to 'sd'
 * */
int leastrm(int sd)
{
	int ret = 0;
	int lst = dist[0];
	for(int p=1;p<rock;p++)
	{
		if( dist[p]-lst < sd)
		{
			ret++; continue;
		}
		lst = dist[p];
	}
	if(end - lst < sd) ret++;
	return ret;
}

int main()
{
	ni(end);
	ni(rock);
	ni(remv);
	//if(rock==0)	{ printf("%d\n",end); return 0;	}
	for(int p=1;p<=rock;p++) ni(dist[p]);
	rock++;
	sort(dist,dist+rock);
	int lt = 0;
	int rt = end;
	int md;
	while(lt < rt)
	{
		md = (lt+rt+1)/2;
		if( leastrm(md)<=remv ) lt=md;
		else rt = md-1;
	}
	printf("%d\n", lt);
}

