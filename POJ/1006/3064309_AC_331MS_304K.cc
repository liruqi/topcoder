//Chinese remainder theorems

#include<iostream>
using namespace std;

int c1,c2,c3,mm;
int ext_gcd(int a,int b,int &x,int &y){
	if(b==0){
	x=1;
	y=0;
	return a;
	}
	int cd,xx,yy;
	cd=ext_gcd(b,a%b,xx,yy);
	x=yy;
	y=xx-a/b*yy;
	return cd;
}
void init(){
	int m1=23,m2=28,m3=33;
	int x,y;
	mm=m1*m2*m3;
	c1=m2*m3;
	c2=m1*m3;
	c3=m1*m2;
	ext_gcd(c1,m1,x,y);
	c1*=x;
	ext_gcd(c2,m2,x,y);
	c2*=x;
	ext_gcd(c3,m3,x,y);
	c3*=x;
}
int r1,r2,r3,cur,res,ks;
int main(){
	init();
	while(cin>>r1>>r2>>r3>>cur && r1>=0){
	res=c1*r1+c2*r2+c3*r3-cur;
	res=(res%mm+mm)%mm;
	if(!res)res=mm;
	cout<<"Case "<<++ks<<": the next triple peak occurs in "<<res<<" days."<<endl;
	}
}
