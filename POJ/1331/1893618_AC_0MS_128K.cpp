#include <iostream>
#include <string.h>
using namespace std;

int Bt[17][8];
int exp(int b,int n)
{
	int i=0;
	int s;
	for(s=1;i<n;i++)
	{
		s *= b;
	}
	return s;
}
int ToDeci(int b,char n[])
{
	int i,j,ans,l=strlen(n);
	for(ans=0,i=l-1,j=0; i>=0; i--,j++)
		ans += (n[i]-'0') * Bt[b][j];
	return ans;
}
int main()
{
	int i,j,n;
	for(i=2;i<17;i++)
	{
		for(j=0;j<8;j++)
		{
			Bt[i][j]=exp(i,j);
		}
	}
	cin>>n;
	char s[3][9],mc;
	int n1,n2,n3;
	while(n--)
	{
        cin>>s[0]>>s[1]>>s[2];
		for(mc='0',i=0;i<3;i++)
			for(j=0;s[i][j]!='\0';j++)
				if(s[i][j]>mc) mc=s[i][j];
		mc -= '0';
        for(i=mc+1;i<17;i++)
        {
            n1=ToDeci(i,s[0]);
            n2=ToDeci(i,s[1]);
            n3=ToDeci(i,s[2]);
            if(n1*n2==n3)
            {
                 cout<<i<<endl;
                 break;
            }
        }
        if(i==17) cout<<"0"<<endl;              
    }
	return 0;
}
