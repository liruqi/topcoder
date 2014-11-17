#include <iostream>
using namespace std;
const int maxf=40;
int f[maxf],top;
long long e[maxf];
void 
factor(int x){
	int i,j;
	for(i=2,top=0;i*i<=x;i++)if(x%i==0){
    	f[top]=i;
    	e[top]=0;
    	do{
    	e[top]++;x/=i;
    	}while(x%i==0);
    	top++;
	}
	if(x>1) {
        f[top]=x;e[top]=1;top++;
    }
}

int n,m;
int judgeD(){
    int i,cnt;
    long long tmp;
    if(n==0)
        return m==1;
    
    if(f[top-1]>n||m==0) return 0;
    if(n>=m) return 1;
    for(i=0;i<top;i++){
        tmp=n;
        cnt=0;
        while(tmp > 0){
            tmp/=f[i];
            cnt+=tmp;
        }
        if(cnt<e[i]) return 0;
    }
    return 1;
}

void 
opt(int d){
if(d>0) cout<<m<<" divides "<<n<<"!"<<endl;
else cout<<m<<" does not divide "<<n<<"!"<<endl;
}

int main(){
while(cin>>n>>m){
	factor(m);
    opt(judgeD());
}
return 0;
}
