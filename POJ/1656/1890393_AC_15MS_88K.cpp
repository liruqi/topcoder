#include <iostream.h>
#define MS 100
bool b[MS][MS];
char str[10];
int main()
{
	int n,i,j,x,y,L,ans;
	for(i=0;i<MS;i++)
		for(j=0;j<MS;j++)
			b[i][j]=0;
	cin>>n;
	while(n--)
	{
		cin>>str;
		switch(str[0])
		{
		case 'W':
			cin>>x>>y>>L;
			for(i=0;i<L;i++)
				for(j=0;j<L;j++)
					b[x+i][y+j]=0;
			break;
		case 'B':
			cin>>x>>y>>L;
			for(i=0;i<L;i++)
				for(j=0;j<L;j++)
					b[x+i][y+j]=1;
			break;
		case 'T':
			cin>>x>>y>>L;
			for(i=0,ans=0;i<L;i++)
				for(j=0;j<L;j++)
					ans += b[x+i][y+j];
			cout<<ans<<endl;
		}
	}
	return 0;
}