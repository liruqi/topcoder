#include<iostream>
using namespace std;
int main()
{
	char a[21],t[21];
	int b[21],i,j,c;
	while(scanf("%s",&a)!=EOF)
	{
		int l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]=='B' || a[i]=='F' || a[i]=='P' || a[i]=='V')
			{
				b[i]=1;
			}
			else if (a[i]=='C' || a[i]=='G' || a[i]=='J' || a[i]=='K' || a[i]=='Q' || a[i]=='S' || a[i]=='X' || a[i]=='Z')
			{
				b[i]=2;
			}
			else if(a[i]=='D' || a[i]=='T')
			{
				b[i]=3;
			}
			else if(a[i]=='L')
			{
				b[i]=4;
			}
			else if(a[i]=='M' || a[i]=='N')
			{
				b[i]=5;
			}
			else if(a[i]=='R')
			{
				b[i]=6;
			}
			else
			{
				b[i]=0;
			}
		}

    	for(c=0,j=0;j<l;j++)
		{
            if(b[j]==0)
				continue;
			else
			{
				if(j-1>=0)
                	if(b[j]==b[j-1])
			        	continue;
				t[c]=b[j]+48;
				c++;
			}
		}

		for(int z=0;z<c;z++)
			cout<<t[z];
		cout<<endl;
	}
	return 0;
}

