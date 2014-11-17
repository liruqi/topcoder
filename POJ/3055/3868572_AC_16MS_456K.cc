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
#ifdef WIN32
typedef __int64 ll;
typedef unsigned __int64 ull;
#else
typedef long long ll;
typedef unsigned long long ull;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef VI::iterator VII;
typedef VS::iterator VSI;

#define EPS 1e-9
#define PI_2 (M_PI*2.0)
#define INF32 0X7F7F7F7F
#define ni(x) (scanf("%d", &x))
#define ns(x) (scanf("%s", x))


/*******************************DO NOT MODIFY THE CODE ABOVE**********************************/


//char set
//not tested yet
struct cs
{
	typedef unsigned char uchar;
	static const char BASE='0';
	uchar dat[10];
	cs(){ clear(); }
	void clear() {memset(dat,0,sizeof(dat));}
	bool operator < (cs q)
	{
		return memcmp(dat, q.dat, sizeof(dat))<0;
	}
	bool operator == (cs q)
	{
		return memcmp(dat, q.dat, sizeof(dat))==0;
	}
	void insert(char c){dat[c-BASE] = 1;}
};



bool check(string str1,string str2)
{
	cs chs1, chs2;
	for(int i=0;i<str1.size();i++) chs1.insert(str1[i]);
	for(int i=0;i<str2.size();i++) chs2.insert(str2[i]);
	return (chs1 == chs2);
}

int valid(const string& str, int idx)
{
	if(idx)
	{
		return (str[idx]>='0') && (str[idx]<='9') && (str[idx+1]>='0') && (str[idx+1]<='9');
	}
	return (str[idx]>='1') && (str[idx]<='9') && (str[idx+1]>='0') && (str[idx+1]<='9');
}

int main(){

	string str1,str2;
	int ks;
	cin>>ks;
	while(ks--)
	{
		cin>>str1;
		cin>>str2;
		
		if(check(str1,str2)) {
			cout<<("friends")
				<<endl;
			continue;
		}
		bool af = 0;
		for(int i=0;i+1<str1.size();i++)
		{
			string exch = str1;
			exch[i]--;
			exch[i+1]++;
			if(valid(exch, i)) 
			{
				if(check(exch, str2))
				{
					af = 1;
					break;
				}
			}
			exch = str1;
			exch[i]++;
			exch[i+1]--;
			if(valid(exch, i)) 
			{
				if(check(exch, str2))
				{
					af = 1;
					break;
				}
			}
		}
		if(!af)
		{
			for(int i=0;i+1<str2.size();i++)
			{
				string exch = str2;
				exch[i]--;
				exch[i+1]++;
				if(valid(exch, i)) 
				{
					if(check(exch, str1))
					{
						af = 1;
						break;
					}
				}
				exch = str2;
				exch[i]++;
				exch[i+1]--;
				if(valid(exch, i)) 
				{
					if(check(exch, str1))
					{
						af = 1;
						break;
					}
				}
			}
		}
		if(af)
		{ 
			cout<<("almost friends")
				<<endl;
		}
		else 
		{
			cout<<("nothing")
				<<endl;
		}
	}
}
