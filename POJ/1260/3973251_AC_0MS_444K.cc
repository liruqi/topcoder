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

int ai[108],pi[108],num;
int dp[108];

int solve()
{
	int i;
	ni(num);
	for(i=1;i<=num;i++)
		ni(ai[i]), ni(pi[i]);
	
	for(i=1;i<=num;i++)
	{
		dp[i]=inf;
		int sum=ai[i];
		for(int s=i-1;s>=0;s--)
		{
			dp[i] <?= dp[s] + (sum+10)*pi[i];
			sum += ai[s];
		}
	}
	cout<<dp[num]<<endl;
}

int main()
{
	int ks;
	ni(ks);
	while(ks--) solve();
}
