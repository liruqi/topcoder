//return value: gcd
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long llong;

llong Ex_Euclid(llong a, llong b, llong &x, llong &y){
	llong xx,yy,cd;
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	cd=Ex_Euclid(b, a%b, xx, yy);
	x=yy;
	y=xx-(a/b)*yy;
	//printf("gcd=%lld\t a=%lld b=%lld x=%lld\t y=%lld\n",cd,a,b,x,y);
	return cd;
}

/*
int main(){
	llong x,y;
	llong cd=Ex_Euclid(99,78,x,y);
	prllongf("gcd=%lld\t x=%lld\t y=%lld\n",cd,x,y);
	getchar();
	return 0;
}
*/
int main(){
	llong x,y,p1,p2,n,m,L,cd,cm;
	//scanf("%lld%lld%lld%lld%lld",&p1,&p2,&m,&n,&L);
	cin>>p1>>p2>>m>>n>>L;
	if(m<n){
		swap(p1,p2);
		swap(n,m);
	}//ensure a > 0
	cd = Ex_Euclid(n-m,L,x,y);
	if((p1-p2)%cd) {
		puts("Impossible");
		return 0;
	}
	else {
		llong k=L/cd;
		x=((x%k)+k)%k;
		x*=(p1-p2+L)%L/cd;
		cout<<x%k<<endl;
	}
	return 0;
}
