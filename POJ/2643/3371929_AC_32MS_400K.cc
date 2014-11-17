#include<map>
#include<set>
#include<iostream>

using namespace std;
char buf[100];
int main(){
	int n;
	scanf("%d\n",&n);
	map<string,string> c2p;
	for(int i=0;i<n;i++){
		gets(buf);
		string can(buf);
		gets(buf);
		string pty(buf);
		c2p[can]=pty;
	}
	scanf("%d\n",&n);
	map<string,int> cnt;
	for(int i=0;i<n;i++){
		gets(buf);
		string can(buf);
		cnt[can]++;
	}
	bool db=0;
	pair<string,int> res=make_pair("",0);
	for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();++it){
		if(it->second > res.second){
			res = *it;
			db=0;
		} else if(it->second == res.second){
			db=1;
		}
	}
	if(db){
		puts("tie");
		return 0;
	}
	puts(c2p[res.first].c_str());
}
