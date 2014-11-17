#include <iostream>
#include <string.h>
#define MS 100
using namespace std;

bool t[MS][MS];
int n[MS];
int P, T;

bool identic(int x,int y)
{
    int i;
 	for(i=1; i<=T; i++) if(t[x][i] != t[y][i])
	    return false;
	return true;
}
int main()
{
    int i, j, k;
    
    memset(n, 0, sizeof(int)*MS);
    memset(t, 0, sizeof(t));
	
    
    cin>>P>>T;
	while(cin>>i>>j && i)
	{
        t[i][j] = 1;
    }
//	for(i=1; i<=P; i++) {for(j=1; j<=T; j++) cout<<t[i][j]<<" ";
//       cout<<endl;}
    int cnt = 1;
    
	for(i=2; i<=P; i++) if(n[i] != -1)
    {
		for(j=1; j<i; j++) if(n[j] != -1)
		{
			if(identic(i,j))
			{	
				n[j] = -1;
				break;
			}
		}
		if(i==j) cnt++;
	}
	
	cout<<cnt<<endl;
    cin>>i;
    return 0;
}
