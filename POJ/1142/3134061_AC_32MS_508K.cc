#include <vector>
#include <iostream>
using namespace std;
#define maxn 35000

bool P[maxn];
vector <int> piv;
void iniprime(){
	int i, j;
	memset(P, 0xff, sizeof(P));
	P[0]=P[1]=0;
	for(i=2; i<maxn; i++)
		for(j=i*i; j<maxn; j+=i)
			P[j]=false;
	for(i=2; i<maxn; i++)
	   if(P[i])
	       (piv).push_back(i);
}

int primenum(int n){
    for(int i=0; i<piv.size() && piv[i]*piv[i]<=n; i++)
        if(n%piv[i]==0)
            return piv[i];

    return n;
}

int digitSum(int n){
    int s=0;
    for(; n; n/=10)
        s+=n%10;
    return s;
}

int main()
{
    int i,n,N;
    iniprime();
    
    while(cin>>N && N){
        while(N++){
            n=N;
            vector <int> pe;
            vector <int> ::iterator vit;
            for(i=0; i<piv.size() && n>1; i++){
                int ys=primenum(n); 
                pe.push_back(ys);
                n/=ys;
            }
            if(pe.size()==1) continue;
            int ds=digitSum(N);
            for(vit=pe.begin(); vit!=pe.end(); ++vit){
                ds-=digitSum(*vit);
            }
            if(!ds){
                cout<<N<<endl;
                break;
            }
        }
    }
    return 0;
}
