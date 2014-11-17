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
 * Problem : (pku) Desert King
 * Author: liruqi
 * Algorithm: 最小比例生成树。二分枚举+Prim
 */
 
#define MSZ 1008
int xx[MSZ], yy[MSZ], zz[MSZ], nd_n;
double dist[MSZ][MSZ];
double cost[MSZ][MSZ];
bool visit[MSZ];
double ssd[MSZ];
double prim(double rate)
{
	double ret=0;
	fill(visit+1, visit+nd_n+1, 0);
	fill(ssd, ssd+nd_n+1, 1e10);
	ssd[1] = 0;
	while(1)
	{
		int t=0;
		for(int i=1;i<=nd_n;i++)
            if(!visit[i] && ssd[i]<ssd[t])
                t=i;
        if(!t) break;
        visit[t] = 1;
        ret += ssd[t];
        for(int i=1;i<=nd_n;i++)
            if(!visit[i])
        		ssd[i] <?= (cost[t][i]-dist[t][i]*rate);
	}
	return ret;
}

int main()
{
	while(ni(nd_n), nd_n)
	{
		for(int i=1;i<=nd_n;i++)
			ni(xx[i]), ni(yy[i]), ni(zz[i]);
		int s,t;
		for(s=1; s<=nd_n; s++)
			for(t=1; t<s; t++)
			{
				dist[s][t] = sqrt( sqr(xx[s]-xx[t]) + sqr(yy[s]-yy[t]) );
				cost[s][t] = abs(zz[s]-zz[t]);
			}
		for(s=1; s<=nd_n; s++)
			for(t=s+1; t<=nd_n; t++)
				dist[s][t]=dist[t][s], cost[s][t]=cost[t][s];
		double lt = 0;
		double cs=0, ds=0;
		for(s=2; s<=nd_n; s++)
			(cs += cost[1][s]), (ds += dist[1][s]);
		double rt = cs/ds;
		double md;
		while(lt < rt - EPS)
		{
			//cout<<lt<<" to "<<rt<<endl;
			md = (lt+rt) / 2;
			double tot = prim(md);
			if(tot < 0)
				rt = md;
			else
				lt = md;
		}
		md = (lt+rt)/2;
		printf("%.3lf\n", md);
	}
}


