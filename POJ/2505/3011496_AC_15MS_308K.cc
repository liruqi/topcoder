#include <stdio.h>
#include <map>
using namespace std;
typedef long long llg;
map<llg, int> dp;//1 win; 2 lose
llg n;
int win(llg p){
	int ret=dp[p],i;
	if(!ret){
		if(p*9>=n) ret=1;
		else for(i=2;i<10;i++)if(!win(i*p)){ret=1;break;}
		if(i==10) ret=2;
		dp[p]=ret;
	}
	return 2-ret;
}

int main(){
	while(~scanf("%I64d",&n))dp.clear(),puts(win(1)?"Stan wins.":"Ollie wins.");
	return 0;
}
