#include <iostream>
using namespace std;

const int maxn=5000001;
int A[maxn];
bool F[maxn<<3];	//8 * maxn
int main()
{
	int i;
	for(i=1; i<maxn; i++)
	{
		A[i]=A[i-1]-i;
		if(A[i]>0 && F[A[i]]==false){
			F[A[i]]=true;
		}
		else {
			A[i]=A[i-1]+i;
			F[A[i]]=true;
		}
	}
	while(cin>>i && i>=0)
		cout<<A[i]<<endl;
	return 0;
}
