#include <algorithm>
#include <iostream>
using namespace std;
int A[11];
int B[11];
int N, S;
int main()
{
	int i,j;
	cin>>N>>S;
	for(i=1; i<=N; i++) A[i]=i;
	while(next_permutation(A+1, A+N+1))
	{
		for(i=N; i>=1; i--)
	 	    B[i]=A[i];
	 	for(i=N; i>1; i--)
	 	{
		 	for(j=1; j<i; j++)
		 	B[j]+=B[j+1];
		}
		if(B[1]==S) break;
    }
    for(i=1; i<N; i++)
    cout<<A[i]<<' ';
    cout<<A[i]<<endl;
    return 0;
}
