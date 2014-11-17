#include <iostream.h>

int i,r,l,n[46];
int main()
{

	cin>>r;

	for(i=0;i<46 && r>=i+2; i++)
		r -= (n[i] = i+2);

	l=i;

	for(i--; r>0 && i>=0; r--)
		n[i--]++;

	n[l-1]+=r;

	for(i=0;n[i];i++)
		cout<<n[i]<<' ';
}
