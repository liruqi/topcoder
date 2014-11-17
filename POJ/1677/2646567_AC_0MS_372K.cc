#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
#define maxl 210

string prswords[3]={
	"beautiful",
	"pretty",
	"lovely"};
string girl[6];
char wish[maxl];
int main()
{
	int g ,w, i, j;
	cin>>g>>w;
	
	for(i=1;i<=g;i++) cin>>girl[i]; gets(wish);
	for(i=1;i<=w;i++) {
		gets(wish);
		int len=strlen(wish);
		int cnt_words=0;
		for(j=0;j<len;j++)if(wish[j]=='!') wish[j]=' ';
		for(j=1;j<len;j++)if(wish[j-1]!=' '&&wish[j]==' ') cnt_words++;
		for(j=0;j<len;j++)wish[j]=tolower(wish[j]);
		
		set <string> words;
		string sw;
		istringstream sin(wish);
		while(sin>>sw)
			words.insert(sw);
		
		bool mention[6]={0,0,0,0,0,0};
		bool praise=0;
		for(j=1;j<=g;j++)
			if(words.find(girl[j])!=words.end())
				mention[0]=mention[j]=1;
		for(j=0;j<3;j++)
			if(words.find(prswords[j])!=words.end())
				praise=1;
		//cout<<"cnt: "<<cnt_words<<"  mention[0] "<<mention[0]<<" praise: "<<praise<<endl;
		if(mention[0]){
			vector<string> list;
			for(int k=1;k<=g;k++)
				if(mention[k])
					list.push_back(girl[k]);
			for(int k=0;k<list.size();k++)
				cout<<list[k]<<(k+1==list.size()?':':' ');
		}
		else 
			cout<<"All:";
		
		if(cnt_words<=9) cout<<" oh"<<endl;
		else if(praise) cout<<" xixi"<<endl;
		else cout<<" hehe"<<endl;
	}
	return 0;
}
