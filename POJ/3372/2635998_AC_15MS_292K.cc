#include <iostream>
using namespace std;

int main(){
int n;
while(cin>>n)
	puts(__builtin_popcount(n)==1?"YES":"NO");
}