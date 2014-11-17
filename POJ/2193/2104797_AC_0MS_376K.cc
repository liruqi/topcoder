#include <iostream>
using namespace std;

int N,M;
long long A[11][2001];

void init(){
	int i,j; 
	memset(A, 0, sizeof(A));
	for(i=1; i<=M; i++)
	A[1][i]=i;
	for(i=2; i<=N; i++)
	{
		for(j = 1<<(i-1); j<=(M>>(N-i)); j++)
		 	A[i][j]+=A[i][j-1] + A[i-1][j/2];	    
	}
}
int main()
{
 	int tc=1;
 	cin>>N;
 	while(cin>>N>>M){
		cout<<"Case "<<tc++<<": n = "<<N
		    <<", m = "<<M<<", # lists = ";
		init();
	 	cout<<A[N][M]<<endl;
	}
	return 0;
}
