#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

const char vowel[6]="aeiou";
set<char> vs(vowel,vowel+5);
bool iv(char c){return vs.find(c)!=vs.end();}
string pw;
bool r1(){
	for(int i=0;i<pw.size();i++)if(iv(pw[i]))return 1;return 0;
}
bool r2(){
	vector<int> cn(pw.size());
	cn[0]=1;
	for(int i=1;i<pw.size();i++){
		if(iv(pw[i])==iv(pw[i-1]))cn[i]=cn[i-1]+1;
		else cn[i]=1;
		if(cn[i]>2)return false;
	}
	return true;
}
bool r3(){
	for(int i=1;i<pw.size();i++)if(pw[i]==pw[i-1])if(pw[i]!='e'&&pw[i]!='o')return false;
	return true;
}
bool accept(){	return r1()&&r2()&&r3(); }

int main(){
	
	while(cin>>pw, pw!="end")
		cout<<("<"+pw+"> is"+(accept()?" ":" not ")+"acceptable.")<<endl;
}
