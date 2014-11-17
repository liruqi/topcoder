#include<algorithm>
#include<iostream>
using namespace std;

template<class T>
void show(T x){cout<<"* "<< x <<endl; }
template<class T>
void show(T b,T e){cout<<"* "; for(;b!=e;b++)

cout<<*b<<" ";cout<<endl; }
typedef unsigned int uint;
#define mx 1100000
bool pt[mx];
uint pn[mx/4],num;
uint df[mx/4];
void sieve(uint left,uint right){
    memset(pt,1,sizeof(pt));
    for(uint i=2;i*i<=right;i++)
    {
        uint j=left/i*i;
	if(j<left) j+=i;
        if(j<i*i) {
		j=i*i;
		if(!pt[j-left]) continue;
        }
        for(;j<=right;j+=i)
            pt[j-left]=0;
    }
}

void getnum(uint left,uint n){
    num=0;
    for(uint i=0;i<n;i++)
        if(pt[i] && left+i>1){
            pn[num++]=left+i;
        }
}

void getdif(){
    for(uint i=0;i+1<num;i++)
        df[i]=pn[i+1]-pn[i];
}

int main(){
    uint left,right;
    while(cin>>left>>right){
        sieve(left,right);
        
        uint n=right-left+1;
        //show(pt,pt+n);
        getnum(left,n);
        if(num<2){
            puts("There are no adjacent primes.");
            continue;
        }
        //show(pn,pn+num);
        //show(num);
        getdif();
        //show(df,df+num-1);
        
        uint* mxp=max_element(df,df+num-1);
        uint* mnp=min_element(df,df+num-1);
        uint mxi=mxp-df;
        uint mni=mnp-df;
        //show(mxi);
        //show(mni);
        
        cout<<pn[mni]<<","<<pn[mni+1]<<" are closest, "
            <<pn[mxi]<<","<<pn[mxi+1]<<" are most distant.\n";
    }
}
