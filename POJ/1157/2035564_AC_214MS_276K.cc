#include <iostream>
using namespace std;
int A[102][102];
int M[102][102];
int F,V;
void init(){
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
}

int main(){
	init();
	cout<<M[1][1];
//	system("pause");
	return 0;
}

