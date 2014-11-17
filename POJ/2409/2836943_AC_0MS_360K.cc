/*
Problem: 1852
*/
#include <iostream>
#include <algorithm>
using namespace std;
int P[40];
int N,K;
bool U[40];
int W[40];
int cyclen(){
    int c=0,i,j;
    memset(U,0,40);
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

void prt(){
    int i;
    for(i=1;i<=N;i++) cout<<P[i]<<" ";
    cout<<endl;
}

void solve(){
    int i;
    int cnt=0;
    W[0]=1;
    for(i=1;i<=N;i++) {
        P[i]=i;
        W[i]=W[i-1]*K;
    }
    for(i=1;i<=N;i++){
        //prt();
        cnt += W[cyclen()];
        rotate(P+1,P+2,P+N+1);
        
    }
    reverse(P+1,P+N+1);
    for(i=1;i<=N;i++){
        //prt();
        cnt += W[cyclen()];
        rotate(P+1,P+2,P+N+1);
    }
    cnt /= 2*N;
    cout<<cnt<<endl;
}

int main()
{
	
	while(cin>>K>>N){
        if(K==0&&N==0) return 0;
        solve();       
	}
}
