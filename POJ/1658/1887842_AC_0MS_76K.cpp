#include <iostream.h>
int main()
{
    long a[4];
    int n;
    long  d;
    cin>>n;
    for(int i =1; i<=n; i++)
    {
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" ";
		if((a[1]-a[0]==a[2]-a[1])&&(a[3]-a[2]==a[2]-a[1])) 
			cout<<a[3]+a[2]-a[1]<<endl;
		else
			cout<<a[3]*a[1]/a[0]<<endl;
     }
     return 0;
}