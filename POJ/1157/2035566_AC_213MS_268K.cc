#include <iostream>
using namespace std;
int A[101][101], M[102][102];
int F,V;

int main(){
	int i,j;
	cin>>F>>V;
	for(i=1; i<=F; i++)
		for(j=1; j<=V; j++)
			cin>>A[i][j];
	for(i=F; i>0; i--){
		j=V-F+i;
		M[i][j]=A[i][j]+M[i+1][j+1];
		for(j--; j>=i; j--)
			M[i][j]=max(A[i][j]+M[i+1][j+1], M[i][j+1]);
	}
	cout<<M[1][1];
	return 0;
}

