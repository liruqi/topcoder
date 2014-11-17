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


#define EPS 1e-9
#define PI_2 (M_PI*2.0)
#define inf 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))
#define pb push_back

int word_n;
int msg_n;
string msg;
string word[600];
int dp[320];

int minremove(int p,int wid)
{
	int tp;
	string & pat = word[wid];
	int pp = pat.size()-1;
	int ret = inf;
	for(tp=p-1;pp>=0 && tp>=0;tp--)
	{
		if(msg[tp] == pat[pp])
		{
			pp--;
			if(pp<0)
			break;
		}
	}
	if(pp>=0) return ret;
	//show(tp);
	for(; tp>=0; tp--)
	{
		ret <?= dp[tp] + (p - tp - pat.size());
	}
	return ret;
}

int reversefind(int p)
{
	int ret = inf;
	int tp;
	for(tp=p-1; tp>=0; tp--)
		ret <?= dp[tp] + (p - tp);
	return ret;
}

int main()
{
	cin>>word_n;
	cin>>msg_n;
	cin>>msg;
	string tmp;
	for(int i=0;i<word_n;i++)
		cin>>word[i];
	fill(dp+1,dp+msg_n+1,inf);
	dp[0]=0;
	for(int p=1;p<=msg_n;p++)
	{
		for(int wid=0;wid<word_n;wid++)
		{
			dp[p] <?= minremove(p,wid);
		}
		dp[p] <?= reversefind(p);
		//cout<<"* "<<dp[p]<<endl;
	}
	cout<<dp[msg_n]<<endl;
}
