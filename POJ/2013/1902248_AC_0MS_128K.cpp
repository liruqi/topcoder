#include <stdlib.h>
#include <iostream>
using namespace std;

char arr[15][30];

int main()
{
    int n,j,i, t=1;
    char strset[20][30];
    while(cin>>n && n)
    {
        cout<<"SET "<<t++<<endl;
        for(i=0;i<n;i++)
	    		cin>>strset[i];         
        for(i=0; i<n; i+=2)
        	cout<<strset[i]<<endl;
        	
        for(i= ((n%2)==0 ? n-1 : n-2);i>=0; i-=2)
        	cout<<strset[i]<<endl;
    }
    return 0;
}