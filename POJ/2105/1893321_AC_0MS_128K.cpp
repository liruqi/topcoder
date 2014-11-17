#include <iostream>
using namespace std;

int i,j,k;
char bin[33];
int b2i[8]={128, 64, 32, 16, 8, 4, 2, 1};
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
    	cin>>bin;
    	for(i=0;i<4;i++)
    	{
    		for(k=0,j=0;j<8;j++)
    			k+=b2i[j]*(bin[i*8+j]-'0');
    		if(i==3) cout<<k<<endl;
            else cout<<k<<".";
    	}
    }
    return 0;
}
