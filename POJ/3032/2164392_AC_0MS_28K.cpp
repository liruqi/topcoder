#include<iostream.h>
#include<string.h>
int main()
{
	int T,n;
	int a[15],temp[15];
	cin>>T;
	while(T--)
	{
		cin>>n;
		int t,i,j,k;
			t=k=0;
			memset(temp,0,sizeof(temp));
			for(i=1;i<=n;i++)
			{
				j=0;
				while(j<i)
				{
					j++;t++;					
					if(t==n) t=0;
					while(temp[t]==1)
					{
						t++;
						if(t==n) t=0;
					}					
				}
				temp[t]=1;a[t++]=i;k++;
				if(t==n) t=0;
				while(temp[t]==1&&k<n)
				{
					t++;
					if(t==n) t=0;
				}			
			}
			for(i=0;i<n;i++)
			cout<<a[i]<<" ";
			cout<<endl;
	}
    return 0;
}
