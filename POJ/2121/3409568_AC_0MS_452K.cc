#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

char buf[1000];
map<string,int> val;
string word[] = {
"negative","zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"
};
int wval[] = {
-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000
};
typedef vector<string> VS;
VS split(){
	stringstream ss((string)buf);
	VS ret;
	string now;
	while(ss>>now)
		ret.push_back(now);
	return ret;
}

int main(){
	int i;
	for(i=0;i<sizeof(wval)/4;i++)
		val.insert(make_pair(word[i],wval[i]));
	
	while(gets(buf)){
		int sgn=1, sum=0, ps=0;
		VS word=split();
		if(0==word.size()) break;
		for(i=0;i<word.size();i++){
			int now=val[word[i]];
			if(now<0){
				sgn=-1;
				continue;
			}
			if(now<1000){
				if(now==100){
					ps*=100;
				} else {
					ps+=now;
				}
			} else {
				sum+=ps*now;
				ps=0;
			}
		}
		sum += ps;
		sum *= sgn;
		cout<<sum<<endl;
	}
}


