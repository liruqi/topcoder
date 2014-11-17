#include <stdio.h>
#include <list>
#include <string.h>
using namespace std;

#define maxn 1000010
#define M 1003433
char str[maxn];
int hv[maxn],cnt,N,C;
int B=137;
typedef list<int> lit;
typedef lit::iterator lii;
lit ht[M];

void addHash(int idx){
	lit & lt=ht[hv[idx]];
	for(lii it=lt.begin(); it!=lt.end(); ++it)
		if(strncmp(str+idx, str+(*it), N)==0)
			return;
	lt.push_back(idx);
	cnt++;
}

void solve(){
	int sln = strlen(str);
	int i,s,mul;
	for(s=0,i=N-1,mul=1;i>=0;i--){
		s += str[i] * mul;
		s %= M;
		mul = mul * B % M;
	}
	//now mul = B ^ N % M
	hv[0] = s;
	addHash(0);
	for(i=1; i+N<=sln; i++)
	{
		hv[i] = hv[i-1] * B + str[i+N-1] - str[i-1]*mul%M;
		hv[i] = (hv[i]%M + M) % M;
		addHash(i);
	}
	
	printf("%d\n",cnt);
}

int main(){
	scanf("%d %d\n",&N,&C);
	gets(str);
	solve();
}