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

#define MAXSZ 1000008
char prime[MAXSZ];
char hprime[MAXSZ];
int main()
{
	VI pn;
	fill(prime+4, prime+MAXSZ, 1);
	int i,j;
	for(i=5;(j=i*i)<MAXSZ;i+=4) if(prime[i])
	{
		pn.push_back(i);
		for(; j<MAXSZ; j+=i)
		prime[j]=0;
	}
	for(;i<MAXSZ;i+=4) if(prime[i]) pn.push_back(i);
	//show(pn.size());
	for(i=0;pn[i]*pn[i]<MAXSZ;i++)
	{
		for(j=i;j<pn.size() && pn[i]*pn[j]<MAXSZ;j++) hprime[ pn[i]*pn[j] ] = 1;
	}
	while(cin>>j && j)
	{
		int cnt=0;
		for(i=5;i<=j;i+=4) cnt+=hprime[i];
		cout<<j<<" "<<cnt<<endl;
	}
}
