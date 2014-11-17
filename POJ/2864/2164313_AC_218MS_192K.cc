#include <iostream>
using namespace std;
int N,D;
bool A[101], tmp;

int main()
{
int i,j;
while(cin>>N>>D && N)
{

for(i=1; i<=N; i++) cin>>A[i];
for(j=2; j<=D; j++)
for(i=1; i<=N; i++)
{
cin>>tmp;A[i]=A[i]&&tmp;
}
for(i=1; i<=N; i++)
if(A[i]) {cout<<"yes"<<endl; break;}
if(i==N+1) cout<<"no"<<endl;

}
return 0;
}
