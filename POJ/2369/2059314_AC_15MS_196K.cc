#include <iostream>
#define Max 1001
using namespace std;
int P[Max], N;
bool V[Max];
int gcd(int a, int b){ 
	return (a == 0) ? b : gcd(b % a, a);
}
//The least common multiple
int lcm(int a, int b){
	return a*b/gcd(a,b);
}

int main(){
	int i,j,cnt,perm=1;
	cin>>N;
	for(i=1; i<=N; i++){
	    cin>>P[i];
	}
	for(i=1; i<=N; i++) if(!V[i]) {
		cnt=1;
		for(j=P[i]; j!=i; j=P[j], cnt++)
			V[j]=1;

		perm=lcm(perm, cnt);
	}
	
	cout << perm << endl;
    //system("pause");
	return 0;
}