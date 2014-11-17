#include<iostream>
#include<algorithm>
using namespace std;
int win(int a, int b){
	if(b==1)return 1;
	if(a/b==1)
		return !win(b,a%b);
	return 1;
}
int main(){
int a,b,d;
while(cin>>a>>b){
if(a+b==0)return 0;
d=__gcd(a,b);
a/=d;
b/=d;
if(a<b)swap(a,b);
puts(win(a,b)?"Stan wins":"Ollie wins");
}
}