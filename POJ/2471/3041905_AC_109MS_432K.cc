#include<iostream>
#include<string>
#include<set>
#include<sstream>
#include<cctype>
#include<algorithm>
using namespace std;
int num,den;
set<string> cur;

void add(string str){
if(str=="BULLSHIT"){num+=cur.size(); den++; cur.clear();}
else cur.insert(str);
}
int main(){
string cs;
while(cin>>cs){
for(int i=0;i<cs.length();i++)if(!isalpha(cs[i]))cs[i]=' ';else cs[i]=toupper(cs[i]);
stringstream ss(cs);
while(ss>>cs)add(cs);
}
int cd=__gcd(num,den);
cout<<num/cd<<" / "<<den/cd<<endl;
}