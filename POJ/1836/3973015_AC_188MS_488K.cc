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

double high[1008];
int high_n;

int dp[2][1008];

int lincs()
{
	fill(dp[0], dp[0]+high_n, 1);
	dp[0][0] = 1;
	for(int p=1;p<high_n;p++)
	for(int s=0;s<p;s++)
	if( high[p] > high[s]+eps )
		dp[0][p] >?= dp[0][s]+1;

}

int ldecs()
{
	fill(dp[1], dp[1]+high_n, 1);
	dp[1][high_n-1] = 1;
	for(int p=high_n-2;p>=0;p--)
	for(int s=p+1;s<high_n;s++)
	if( high[p] > high[s]+eps )
		dp[1][p] >?= dp[1][s]+1;

}

int solve()
{
	int ret = 0;
	
	for(int s=0;s<high_n;s++)
	for(int t=s+1;t<high_n;t++)
		ret >?= dp[0][s]+dp[1][t];
	cout<<high_n - ret<<endl;
}

int main()
{
	cin>>high_n;
	int i;
	for(i=0;i<high_n;i++) cin>>high[i];
	lincs();
	ldecs();
	solve();
}
