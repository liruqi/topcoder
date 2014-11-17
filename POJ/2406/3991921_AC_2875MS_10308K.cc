#include<string.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;

template<class T>
void show(T x){ cout<< "# "<< x <<endl; }
template<class T>
void show(T b,T e){ cout<<"$ "; for(T i=b;i!=e;i++) cout<<*i<<", ";cout<<endl; }


/*
both text and pattern index start from 0
*/
struct KMP
{
	VI last;
	string patt;
	
	void prefix(string & pat)
	{
		int m=pat.size();
		patt = pat;
		last.resize(m);
		int k=-1, q;
		last[0] = k;
		for(q=1;q<m;q++)
		{
			while(k>=0 && pat[k+1]!=pat[q])
				k = last[k];
			if(pat[k+1] == pat[q])
				k++;
			last[q]=k;
		}
		//show(last.begin(), last.end());
	}
	
	void solve()
	{
		int size = patt.size();VI res(size);
		fill(res.begin(), res.end(), 1);
		for(int i=0;i<size;i++) if(1==res[i])
		{
			if(res[size-1]>1) break;
			int cnt=1;
			for(int now=i;i+1+now<size;(now+=i+1), cnt++, res[now]=cnt)
			{
				int k=now+i+1;
				if(last[k]!=now) {
					break;
				}
			}
		}
		cout<<res[size-1]<<endl;
	}
	
	//return the greatest length that txt can match the pattern
	int match(string & txt)
	{
		int n = txt.size();
		int i,k=-1;
		int ret = -1;
		for(i=0;i<n;i++)
		{
			while(k>=0 && patt[k+1]!=txt[i])
				k = last[k];
			if(patt[k+1] == txt[i])
			{
				k++;
				ret >?= k;
			}
			if(k+1==last.size())
				return last.size();
		}
		return ret + 1;
	}
};

int main()
{
	
	KMP kmp;

	while(1)
	{
		string par;
		cin>>par;if(par==".") break;
		kmp.prefix(par);
		kmp.solve();
	}
}
