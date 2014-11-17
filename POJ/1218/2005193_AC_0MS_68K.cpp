#include <iostream.h>
#include <string.h>
bool lock[101];

int main()
{
 	int i,j,n,t;
 	cin>>t;
 	while(t--)
 	{
        memset(lock, 0, sizeof(lock));
	 	cin>>n; 	
	 	for(i=2;i<=n;i++)
	 	{
		 	for(j=i;j<=n;j+=i)
		 		lock[j] = 1 - lock[j];
	    }
	    j=1;
		for(i=2; i<=n; i++) if(!lock[i]) j++;
		cout<<j<<endl;
	}
	return 0;
}
