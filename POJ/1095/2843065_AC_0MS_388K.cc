#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 20
int Catl[maxn];
string tree(int n,int k){
    if(n<2) return "X";
    int t=n-1,j;
    for(j=0;j<=t;j++)
        if(k < Catl[j]*Catl[t-j]){
            int Ln=j;
            int Rn=t-Ln;
            int Lk=k/Catl[Rn];
            int Rk=k%Catl[Rn];
            string ret("X");
            if(Ln>0)
                ret = "(" + tree(Ln,Lk) + ")" + ret;
            if(Rn>0)
                ret = ret + "(" + tree(Rn,Rk) + ")";
            return ret;
        }
        else 
            k-=Catl[j]*Catl[t-j];
}
int main(){
	int i,j,t,n; 
	Catl[0]=1;
	for(i=1;i<maxn;i++) {
	    for(j=0;j<i;j++)
	    {
            Catl[i]+=Catl[j]*Catl[i-j-1];
        }
    }
	while(cin>>n && n){
        for(t=0;t<maxn;t++)
        if(n<Catl[t])
            break;
        else
            n-=Catl[t];
        cout<<tree(t,n)<<endl;
    }
}
