#include <iostream>
#define MS 64
using namespace std;

bool pth[MS];

int countp(int pos)
{
	int lp=0,rp=1,cnt = 1,i;
	for(i=pos-1; rp>lp; i--)
	{
		if(pth[i])
		{
			rp ++; cnt++;
		}
		else
			lp++;
	}
	return cnt;	
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int i,jj,j=0,ri;	//right index
		cin>>n;
		memset(pth,0,sizeof(pth));
		cin>>ri;
		j=ri;
		ri++;
		pth[ri]=1;
		for(i=1;i<n;i++)
		{
			cin>>jj;
			ri += (jj-j + 1);
			j = jj;
			pth[ri] = 1;
		}
		j = 2*n;

		for(i=1;i<=j;i++)
		{
			if(pth[i])
				cout<<countp(i)<<" ";
		}
		cout<<endl;
	}
	return 0;
}

