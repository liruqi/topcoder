#include <iostream>
#include <string>
using namespace std;

string P[2][5]={{"anti", 
				 "post",
				 "pre",
				 "re",
				 "un"},
                {"against *",
				 "after *",
				 "before *",
				 "* again",
				 "not *"}
               };
string S[2][5]={{"er",
				 "ing",
				 "ize",
				 "s",
				 "tion"},
                {"one who *s", 
				 "to actively *", 
				 "change into *",
				 "multiple instances of *",
				 "the process of *ing"}
               };

void printsuf(string s){
	for(int si=0; si<5; ++si)
	{
        int p = s.rfind(S[0][si]);
		if(p>=0 && p == s.length() - S[0][si].length())
		{
			// cut off the suffix
			string ss(&s[0], &s[p]);
			string ps = S[1][si];
			for(int i=0; i<ps.length(); i++)
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
	for(int pi=0; pi<5; ++pi)
	{
		if(s.find(P[0][pi]) == 0)
		{
			// cut off the prefix
			string ss = &s[P[0][pi].length()];
			string ps = P[1][pi];
			for(int i = 0; i<ps.length(); i++)
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
	
	cin>>n;
	while(n--){
		string str;
		cin>>str;
		print(str);
		cout<<endl;
	}
	return 0;
}
