#include <iostream>
#include <algorithm>
using namespace std;
typedef long long llg;

int P[25];
bool U[25];
llg W[25],N;
int cyclen(){
    int c=0,i,j;
    memset(U,0,25);
    for(i=1;i<=N;i++)if(!U[i]){
        c++;
        j=i;
        while(!U[j]) {
            U[j]=1;
            j=P[j];
        }
    }
    return c;
}

void solve(){
    int i;
    llg cnt=0;
    if(N){
    for(i=1;i<=N;i++)
    	P[i]=i;
    for(i=1;i<=N;i++){
        cnt += W[cyclen()];
        rotate(P+1,P+2,P+N+1);
    }
    reverse(P+1,P+N+1);
    for(i=1;i<=N;i++){
        cnt += W[cyclen()];
        rotate(P+1,P+2,P+N+1);
    }
    cnt /= 2*N;
    }
    cout<<cnt<<endl;
}

int main()
{
	int i;
	W[0]=1;
	for(i=1;i<=24;i++) 
        W[i]=W[i-1]*3;
	while(cin>>N){
        if(N<0) return 0;
        solve();
	}
}