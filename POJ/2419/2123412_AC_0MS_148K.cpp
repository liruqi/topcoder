#include <iostream>
#include <string.h>
const int MS = 100;
using namespace std;
bool t[MS][MS];
int n[MS];
int P, T;
bool f;

int main()
{
    int i, j, k;
    cin>>P>>T;
	while(cin>>i>>j)
        t[i][j] = 1;

    int cnt = 1;
    
	for(i=2; i<=P; i++)
    {
		for(j=1; j<i; j++) if(n[j] != -1)
		{
	        f=1;
	        for(k=1; k<=T; k++) if(t[i][k] != t[j][k])
	        {
			 	f=0; break;
		    }
			if(f)
			{
				n[j] = -1;
				break;
			}
		}
		if(i==j) cnt++;
	}
	
	cout<<cnt<<endl;
    return 0;
}

