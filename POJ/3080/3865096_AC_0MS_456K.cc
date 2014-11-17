//pku3080

#include<string.h>
#include<iostream>
#include<string>
using namespace std;

// index start from 1
int last[204];
void prefix(char pat[], int m)
{
	int k=0;
	int q;
	last[1] = 0;
	for(q=2;q<=m;q++)
	{
		while(k>0 && pat[k+1]!=pat[q])
			k = last[k];
		if(pat[k+1] == pat[q])
			k++;
		last[q]=k;
	}
}

int str_n;
char sa[4000][204];

int kmp(char pat[],int plen,char txt[])
{
	int tlen = strlen(txt+1);
	int i,q=0;
	int ret=0;
	for(i=1;i<=tlen;i++)
	{
		while(q>0 && pat[q+1]!=txt[i])
			q = last[q];
		if(pat[q+1] == txt[i])
		{
			q++;
			ret >?= q;
		}
		if(q==plen)
			return plen;
	}
	return ret;
}

// index start from 1
string solve(char pat[],int plen)
{
	prefix(pat, plen);
	int mlen=plen;
	for(int i=1;i<str_n;i++)
	{
		mlen <?= kmp(pat,plen,sa[i]);
	}
	return string(pat+1,pat+1+mlen);
}

#define ni(x) (scanf("%d",&x))
#define ns(x) (scanf("%s",x))


int main()
{
	int ks;
	ni(ks);
	
	while(ks--)
	{
		ni(str_n);
		if(!str_n)break;
		for(int i=0;i<str_n;i++)
			ns(sa[i]+1);
		int len = strlen(sa[0]+1);
		string ans = "";
		for(int p=0;p<len;p++)
		{
			string res = solve(sa[0]+p, len-p);
			//cout<<"$ "<<p<<" -> "<<res<<endl;
			if(res.length() > ans.length())
				ans = res;
			else if(res.length() == ans.length() && res<ans)
				ans = res;
		}
		if(ans.size() < 3)
		{
			ans = "no significant commonalities";
		}
		cout<<ans<<endl;
	}
}

