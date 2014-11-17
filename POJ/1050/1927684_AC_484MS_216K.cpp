#include <iostream>
#define MS 105
using namespace std;
int a[MS][MS], m[MS][MS];

int main()
{
	int i,j,n,ii,jj,max;
	cin>>n;
	for(i=1;i<=n;i++) 
        for(j=1;j<=n;j++)
		{
            cin>>a[i][j];
        }
    max = a[0][0];
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
		{
            m[i][j] = a[i][j];
            for(jj=j+1;jj<=n;jj++) m[i][jj] = m[i][jj-1] + a[i][jj];
            for(ii=i+1;ii<=n;ii++)
            {
                m[ii][j] = m[ii-1][j] + a[ii][j];
                for(jj=j+1;jj<=n;jj++)
                {
                    m[ii][jj] = m[ii-1][jj] + m[ii][jj-1] - m[ii-1][jj-1] + a[ii][jj];                   
                }
            }
            for(ii=i;ii<=n;ii++) for(jj=j;jj<=n;jj++)
                if(m[ii][jj] > max) max = m[ii][jj];                 
        }
	cout<<max<<endl;
	cin>>i;
	return 0;
}
