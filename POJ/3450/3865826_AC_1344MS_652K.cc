//pku3450

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


template<class T>
struct KMP{
	VI last;
	vector<T> patt;
	//pattern index start from 0
	void prefix(vector<T> pat)
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
		// show(patt.begin(), patt.end());
		// show(last.begin(), last.end());
	}
	
	//return the greatest length that txt can match the patten
	int match(vector<T> txt)
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
		// show("pattern :");
		// show(patt.begin(), patt.end());
		// show("text :");
		// show(txt.begin(), txt.end());
		// show(ret+1);
		return ret + 1;
	}
};


int str_n;
char sa[4000][208];


// index start from 1
string solve(char pat[],int plen)
{
	KMP<char> kmp;
	kmp.prefix(vector<char>(pat,pat+plen));
	int mlen=plen;
	for(int i=1;i<str_n;i++)
	{
		mlen <?= kmp.match(vector<char>(sa[i], sa[i]+strlen(sa[i])));
	}
	return string(pat,pat+mlen);
}

#define ni(x) (scanf("%d",&x))
#define ns(x) (scanf("%s",x))

int main()
{
	while(1)
	{
		ni(str_n);
		if(!str_n)break;
		for(int i=0;i<str_n;i++)
			ns(sa[i]);
		int len = strlen(sa[0]);
		string ans = "";
		for(int p=0;p<len;p++)
		{
			string res = solve(sa[0]+p, len-p);
			if(res.length() > ans.length())
				ans = res;
			else if(res.length() == ans.length() && res<ans)
				ans = res;
		}
		if(ans == "")
		{
			ans = "IDENTITY LOST";
		}
		cout<<ans<<endl;
	}
}

