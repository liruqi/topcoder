#include <stdlib.h>
#include <iostream>
using namespace std;

char arr[9][30];

int main()
{
    int n,j,i, t=1;
    char strset[20][30];
    while(cin>>n && n)
    {
        cout<<"SET "<<t++<<endl;
        for(i=0,j=0;i<n;i++)
        {
	    		if(i%2)	cin>>strset[j++];
          else
          {
						cin >> strset[8];
						cout << strset[8]
								 << endl;
					}
        }
        for(j--;j>=0;j--)
            cout<<strset[j]<<endl;
    }
    return 0;
}