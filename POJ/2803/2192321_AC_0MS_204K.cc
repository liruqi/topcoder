#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> pref;
map<string, string> suf;

void init()
{
	pref["anti"] = "against *";
	pref["post"] = "after *";
	pref["pre"]  = "before *";
	pref["re"]   = "* again";
	pref["un"]	 = "not *";
	//end of initializing prefixes
	suf["er"]  = "one who *s";
	suf["ing"] = "to actively *";
	suf["ize"] = "change into *";
	suf["s"]   = "multiple instances of *";
	suf["tion"]= "the process of *ing";
	//end of initializing suffixes
}

void printsuf(string s){
    map<string, string>::iterator fit;
	for(fit=suf.begin(); fit!=suf.end(); ++fit)
	{
        int p = s.rfind(fit->first);
		if(p>=0 && p == s.length()-(fit->first).length()) 
		//it is possible for s.find(fit->first) == string::npos  here!!!
		{
			// cut off the suffix!
			string ss(&s[0], &s[( s.length()-(fit->first).length() )]);
			string ps = suf[(fit->first)];
			int i=0;
//			cout<<" sub string: "<<ss<<endl;
			for(; i<ps.length(); i++)
			{
				if(ps[i]=='*')
					cout<<ss;
				else
					cout<<ps[i];
			}
			return ;
		}
	}
	cout<<s;
}

void print(string s){
	map<string, string>::iterator fit;
	for(fit=pref.begin(); fit!=pref.end(); ++fit)
	{
		if(s.find(fit->first) == 0)
		{
			// cut off the prefix!
			string ss = &s[(fit->first).length()];
			string ps = pref[(fit->first)];
			int i = 0;
			for(; i<ps.length(); i++)
			{
				if(ps[i]=='*')
					printsuf(ss);
				else
					cout<<ps[i];
			}
			return ;
		}
	}
	printsuf(s);
}

int main()
{
	int n;
	string str;
	init();
	cin>>n;
	while(n--){
		cin>>str;
		print(str);
		cout<<endl;
	}
	return 0;
}
