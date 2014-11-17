#include <algorithm>
#include <iostream>
using namespace std;

int C,N,A[1001];
int main()
{
	int i,m,front=0,cnt=0,tc=1;
	while( cin>>C>>N && C)
	{
		cnt=0; front=0;
		memset(A+1, 0, C*N*sizeof(int));
		for(i=0; i<N; i++) {
			cin>>m;
			A[m]=1;
		}

		for(i=C*N; i>0; i--)
		{
			if(A[i])
			{
				if(front>0)
					front--;
				else 
					cnt++;
			}
			else 
				front++;
		}
		cout<<"Case "<<tc++<<": "
			<<cnt<<endl;
	}
	return 0;
}