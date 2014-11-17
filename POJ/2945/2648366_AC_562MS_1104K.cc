//poj2945

#include <stdio.h>
#include <map>
#include <string>
using namespace std;

typedef map<string, int> msi;
typedef msi::iterator mit;
char buf[30];
int C[20001];
int main() {
	int m,n,i;
	while (EOF!=scanf("%d%d",&n,&m) && (m+n)){
		memset(C,0,n*4);
		msi strc;
		for(i=n;i;i--) {
			scanf("%s",buf);
			string dna(buf, buf+m);
			strc[dna]++;
		}
		for(mit itr=strc.begin(); itr!=strc.end();++itr)
			C[itr->second]++;
		for(i=1;i<=n;i++)
			printf("%d\n",C[i]);
	}
	return 0;
}