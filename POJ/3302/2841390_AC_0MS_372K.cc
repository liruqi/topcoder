#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s1,s2;

bool sub(){
int i,j=0;
for(i=0;i<s1.size();i++)
	if(s1[i]==s2[j]){
		j++;if(j==s2.length())return 1;
	}
return 0;
}

bool sol(){
cin>>s1>>s2;
if(sub())return 1;
reverse(s2.begin(),s2.end());
if(sub())return 1;
return 0;
}
int main(){
	int tc;cin>>tc;while(tc--)puts(sol()?"YES":"NO");
}