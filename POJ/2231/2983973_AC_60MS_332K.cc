#include <algorithm>
#include <cstdio>
using namespace std;
int i,N;
long long A[10001],S[10001],sum;
int main(){
scanf("%d",&N);
for(i=1;i<=N;i++)scanf("%I64d",A+i);
sort(A+1,A+i);
for(i=1;i<=N;i++)S[i]=S[i-1]+A[i];
for(i=1;i<=N;i++)sum+=A[i]*i-S[i]+S[N]-S[i]-A[i]*(N-i);
printf("%I64d\n",sum);
}