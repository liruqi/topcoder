#include<iostream.h>
int main()
{
	int i,j,k,a[52],b[52],n,r,p,c;
	while(cin>>n>>r && (n||r))
	{
		for(i=0;i<n;i++) 
			a[i]=n-i;
		for(i=1;i<=r;i++)
		{
			cin>>p>>c;
			for(j=p-1,k=0;j<p+c;j++,k++)
				b[k]=a[j];
			for(j=p-2;j>=0;j--)
				a[j+c]=a[j];
			for(j=0;j<c;j++)
				a[j]=b[j];
		}
		cout<<a[0]<<endl;
	}
	return 0;
}
