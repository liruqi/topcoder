#include<iostream>
using namespace std;
#define maxn 16
int A[maxn]={1,3},s,i;
int main()
{
for(s=1,i=2;i<maxn;i++) A[i] = A[i-1]*3 + s*2,s += A[i-1];
while(cin>>i && i>=0)cout<<((i&1)?0:A[i/2])<<endl;
}
