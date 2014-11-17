#include <iostream>
using namespace std;

const int Max=100000;
int A[300];
bool F[Max];
int N,G;

bool distinct(int x){
	 int i,j;
	 memset(F, 0, sizeof(bool) * x);
	 for(i=0; i<G; i++) {
	 	 j=A[i]%x;
	 	 if(F[j]) return false;
	 	 else F[j]=1;
     }
     return true;
}

int main()
{
 	int i,j;
 	cin>>N;
 	while(N--){
		cin>>G;
		for(i=0; i<G; i++) 
		    cin>>A[i];
		for(i=G; i<Max; i++) 
			if(distinct(i))
			{
		 	cout<<i<<endl;
		 	break;
			}
    }
    
    return 0;
}
