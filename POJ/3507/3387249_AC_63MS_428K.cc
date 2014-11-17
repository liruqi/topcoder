#include<iostream>
using namespace std;

int s[6];
int main(){
while(1){
scanf("%d",s);
int mx=s[0];
int mn=s[0];
int i,sum=s[0];
for(i=1;i<6;i++){
scanf("%d",s+i);if(mx<s[i])mx=s[i];if(mn>s[i])mn=s[i];sum+=s[i];
}
if(mx==0 && mn==0)break;
sum-=mx;sum-=mn;
double res=(double)sum/4;
cout<<res<<endl;
}
}
