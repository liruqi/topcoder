#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D[22][22],N,S,i,j;

int main(){
	cin>>N>>S;
	D[1][1]=S;
	for(i=1;i<=N;i++)
		for(j=1;j<=i;j++){
			D[j][i]=S;
			S = (S==9)?1:S+1;
		}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(i>j) putchar(' ');
			else cout<<D[i][j];
			putchar(j==N?'\n':' ');
		}
	}
}
