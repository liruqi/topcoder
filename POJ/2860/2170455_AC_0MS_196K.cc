#include <iostream>
#include <math.h>
using namespace std;

int N;	//N identical blocks 
int K;	//K rooms 
int M;	//M blocks 
int A[11];

int main()
{
int i, cnt=0;
cin>>N>>M>>K;
for(i=1; i<=K; i++)  cin>>A[i];
for(i=1; i<=K; i++) {
cin>>A[0];
cnt+=abs(A[i]-A[0]);
}
cout<<(cnt/2)<<endl;
return 0;
}
