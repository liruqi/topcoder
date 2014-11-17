#include<iostream>
using namespace std;
int Q[6][50];

int main()
{
	int n,r=0;
	int i,j,k;
	for(i=0; i<10; i++)
		Q[1][i]=1;
	for(i=1; i<6; i++)
		for(j=0; j<=i*9; j++)
			for(k=0; k<=9; k++) if(j-k>=0)
				Q[i][j]+=Q[i-1][j-k];
	cin>>n;	n/=2;
	for(i=0; i<=9*n; i++)
		r+=Q[n][i]*Q[n][i];
	cout<<r;
	return 0;
}
