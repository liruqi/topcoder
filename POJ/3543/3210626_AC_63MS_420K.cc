#include<iostream>
#include<cmath>
using namespace std;
int a,b,c,d;
int min(int a,int b) {return ((a)<(b)?(a):(b));}

int main(){
while(cin>>a>>b){
if(a==0&&b==0){cout<<("Impossible\n");continue;}
c=min(a,b);
d=min(c+1,a+b-c);
a=c+d;
for(d=1;d*d<=a;d++);
cout<<d-1<<endl;
}
return 0;
}
