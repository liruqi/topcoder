#include <iostream>
using namespace std;

int A[31][31];
void init()
{
	int i,j;
	for(i=1; i<=30; i++)
	A[0][i]=i;
	for(i=1; i<=30; i++)
	for(j=1; j<=30; j++)
	A[i][j]=A[i-1][j-1]+A[i][j-1]+1;
}
int main()
{
	int L,G,tc=1;
	init();
	while(cin>>G>>L && G>0)
	cout<<"Case "<<tc++<<": "<<A[L][G]<<endl;
	return 0;
}
