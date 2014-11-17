#include<iostream>
#include<algorithm>
#define mx 1000
using namespace std;
typedef long long ll;

int M, D, L, R;
int mm,dd,xl,xr;

ll ext_gcd(ll a,ll b,ll &x,ll &y){
    ll xx,yy,cd;
    if(b){
        cd=ext_gcd(b,a%b,xx,yy);
        x=yy;
        y=xx-a/b*yy;
        return cd;
    }
    x=1;
    y=0;
    return a;
}

int getx(int z){
	ll x,y;
	ext_gcd((ll)dd,(ll)mm,x,y);
	return (x*z%mm+mm)%mm;
}

int solve(){
	if(L>=M) return -1;
	if(R>=M) R=M-1;
	int cd=__gcd(M,D);
	xl=L/cd;
	xr=R/cd;
	int ml=L%cd;
	int mr=R%cd;
	if(xl==xr&&ml>0)return -1;
	mm=M/cd;
	dd=D/cd;
	int i, x=0;
	for(i=0;i<mx;i++,x+=dd,x%=mm){
		if(x>=xl&&x<=xr)
			return i;
	}
	int ret=mm;
	for(i=xl;i<=xr;i++)
	{
		int can=getx(i);
		if(can<ret) ret=can;
	}
	return ret;
}

int main(){
	int ks;
	cin>>ks;
	while(ks--) 
		cin>>M>>D>>L>>R, cout<<solve()<<endl;
}


