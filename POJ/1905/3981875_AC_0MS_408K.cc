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



double ol, dc, co;


#define eps 1e-4
#define M_PI 3.14159265358979323846

double getval(double ang)
{
	if(ang < eps) return 1 - ang/2;
	return sin(ang) / ang;
}


int main () {

	while( scanf("%lf", &ol) )

	{

		if(ol < 0) break;

		scanf("%lf", &dc);

		scanf("%lf", &co);

		double rat = 1.0/(1.0 + dc*co);

		double lt = 0;

		double rt = M_PI / 2;

		

		while(lt + 1e-12 < rt)

		{

			double md = (lt+rt)/2;

			if( getval(md) < rat ) rt = md;

			else lt = md;

		}
		double ans = ol*tan(lt/2.0)/2.0;

		printf("%.3lf\n", ans);

	}

}
