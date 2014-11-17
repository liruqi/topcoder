/*
k*a+b - a 必胜 k>=2
a+b - a 必败
a - b 必胜

k*a+b - a
a+b - a 必胜
a - b 必败

k*n+1 - n 必胜 k>=2
2n+1 - n 必胜
n+1 - n 必败
n - 1 必胜

n   1  2n+1 n+1
n+1 n  3n 
*/
//a>b, (a,b)=1
#include <iostream>
#include <algorithm>
using namespace std;

bool win(int a, int b){
	if(b==1)return true;
	if(a/b==1)
		return !win(b,a%b);
	return true;
}

int main(){
int a, b, d;
while(cin>>a>>b){
if(a+b==0)return 0;
d=__gcd(a,b);
a/=d;
b/=d;
if(a<b)swap(a,b);
puts(win(a,b)?"Stan wins":"Ollie wins");
}
}