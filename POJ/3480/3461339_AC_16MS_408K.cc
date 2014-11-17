//poj3480
#define maxn 101
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <list>
#include <cctype>
using namespace std;

int main(){
	int n,ks,a,r,c;cin>>ks;
	while(ks--){
        cin>>n;r=c=0;for(int i=n;i;i--){cin>>a;if(a==1)c++;r^=a;}
        puts(((r>0)+(c==n))%2?"John":"Brother");
    }
}
