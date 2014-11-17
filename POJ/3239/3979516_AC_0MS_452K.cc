#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main ( ) { 
	int n , i, odd;
	while(cin>>n){
		if(n<4) break;
		else if((n/2)%3!=1){
			cout<<2;
			for(i=4;i<=n;i+=2)cout<<" "<<i;
			for(i=1;i<=n;i+=2)cout<<" "<<i;
		}else{
			if(n&1) {n--;odd=1;} else odd=0;
			cout<<n/2 ;
			for(i=n/2+1;i!=n/2-1;i=(i+2)%n)cout<<" "<<i+1;
			for(i=(i+n-2)%n;i!=n/2-1;i=(i+n-2)%n) cout<<" "<<n-i;
			cout<<" "<<n-i; if (odd) cout<<" "<<n+1;
		}
		cout<<endl;
	}
	return 0 ;
}
