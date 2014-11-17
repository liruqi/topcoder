#include <iostream>
using namespace std;

int t[310];
int i,j,k,N,n;
int main()
{
	for(i=1;i<305;i++)
		t[i]=(i*(i+1))/2;
	cin>>N;
	for(i=1;i<=N;i++)
	{
		int s=0;
        cin>>n;
		cout<<i<<" "<<n<<" ";
		
		for(j=1;j<=n;j++)
			s+=j*t[j+1];
		cout<<s<<endl;
	}
}
