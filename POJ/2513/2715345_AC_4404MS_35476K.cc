#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxv = 500010;
int top;

typedef map <string, int> msi;
typedef msi::iterator msit;
msi cid;

int degree[maxv];
int A[maxv];
bool vst[maxv];

int root(int p){
	int r=p;
	while(A[r]>0) r=A[r];
	if(r!=p) A[p]=r;
	return r;
}

bool connected(){
	int father=root(1), i;
	for(i=2;i<=top;i++)
		if(father!=root(i))
			return false;
	return true;
}

void solve(){
	int i,cnt=0;
	for(i=1;cnt<3 && i<=top;i++) if(degree[i]&1){
		cnt++;
	}
	if((0==cnt||2==cnt) && connected()) puts("Possible");
	else puts("Impossible");
}


char buf1[20], buf2[20];
int main(){
	int sid,eid;
	top=0;
	while(EOF != scanf("%s%s",buf1,buf2)){
		string start(buf1);
		string end(buf2);
		if(cid.find(start)==cid.end()){
			top++;
			sid=top;
			cid[start]=sid;
		}
		else sid=cid[start];
		if(cid.find(end)  ==cid.end()){
			top++;
			eid=top;
			cid[end]=eid;
		}
		else eid=cid[end];
		
		degree[sid]++;
		degree[eid]++;
		int srt=root(sid);
		int ert=root(eid);
		if(srt!=ert){//combine
			A[ert]=srt;
		}
	}
	solve();
	return 0;
}