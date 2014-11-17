/*

ID: liruqi1

PROG: lamps

LANG: C++

*/

#include <iostream>

#include <algorithm>

#include <fstream>

#include <cmath>

using namespace std;
const int maxn = 110;
int N,idx[maxn];
char fs[maxn];//final configuration,1 off; 2, on; 0, undetermined
char buf[maxn];
char stk[maxn][maxn];
int top;

void prt(char *str){
	int i;
	for(i=1;i<=N;i++)
		cout<<(int)(str[i]-1);
	cout<<endl;
}

void operate(int id){
	int i;
	switch (id){
		case 0:
		for(i=1;i<=N;i++)
			buf[i]=3-buf[i];
		break;
		case 1:
		for(i=1;i<=N;i+=2)
			buf[i]=3-buf[i];
		break;
		case 2:
		for(i=2;i<=N;i+=2)
			buf[i]=3-buf[i];
		break;
		case 3:
		for(i=1;i<=N;i+=3)
			buf[i]=3-buf[i];
		break;
	}
}

bool fitpat(){
	int i;
	for(i=1;i<=N;i++)if(fs[i] && fs[i]!=buf[i]) return false;
	return true;
}

void getconf(int c)
{
	int i,j;
	for(i=0;i<(1<<4);i++)if(__builtin_popcount(i)==c){
		memset(buf,2,1+N);
		for(j=0;j<4;j++)if((1<<j)&i)
			operate(j);
		//prt(buf);
		if(fitpat()){
			memcpy(stk[top]+1, buf+1, N),top++;
		}
	}
}

bool cmp(int p,int q){ return memcmp(stk[p]+1,stk[q]+1, N)<0; }

int main(){
	int x,C,i,j;


    cin>>N>>C;
    while(cin>>x && x>0) fs[x]=2;
    while(cin>>x && x>0) fs[x]=1;
    for(top=i=0;i<=4;i++)
    	if((i<=C) && ((C-i)%2 == 0))
    		getconf(i);
    //cout<<"*"<<top<<endl;
    for(i=0;i<top;i++)
    	idx[i]=i;
    sort(idx,idx+top,cmp);
    for(i=0;i<top;i++){
    	prt(stk[idx[i]]);
    }
    if(!top) cout<<"IMPOSSIBLE"<<endl;
    return 0;
}


