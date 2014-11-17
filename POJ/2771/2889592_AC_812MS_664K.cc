#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;
const int maxn = 510;

typedef struct _stud{
    int height;
    string music;
	string sport;
}stud;

stud boy[maxn],girl[maxn];
bool adj[maxn][maxn];
bool vst[maxn];
int N,btp,gtp;
int match[maxn];

void graph(){
	int i,j;
	memset(adj,0,sizeof(adj));
	for(i=0;i<btp;i++)
		for(j=0;j<gtp;j++)
		{
			if(abs(boy[i].height-girl[j].height)<=40 && boy[i].music==girl[j].music && boy[i].sport!=girl[j].sport)
				adj[i][j]=true;
		}
}

bool dfs(int p){
	int i,t;
	for(i=0;i<gtp;i++)
		if(adj[p][i] && !vst[i]) {
            vst[i] = true;
            t = match[i];
            match[i] = p;
            if(t == -1 || dfs(t)) {
                return true;
            }
            match[i] = t;
        }
	return false;
}

void solve(){
	int i,cnt=0;
	memset(match,-1,N*4);
	for(i=0;i<btp;i++) {
		memset(vst,0,N);
		if(dfs(i))
			cnt++;
	}
	cout<<(N-cnt)<<endl;
}

int main()
{
    char sex[10];
    int i,ht,cnt=0;
	cin>>N;
	while(cin>>N){
	    btp=gtp=0;
        
    	for(i=1;i<=N;i++){
    	    cin>>ht>>sex;
			if(sex[0]=='M'){
				boy[btp].height=ht;
				cin>>boy[btp].music>>boy[btp].sport; 
				btp++;
			}
			else {
				girl[gtp].height=ht;
				cin>>girl[gtp].music>>girl[gtp].sport;
				gtp++;
			}
    	}
		graph();
        solve();
    } 
    return 0;
}
