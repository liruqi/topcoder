#include <iostream.h>



int i,r,l;

int n[46];

int main()

{

	cin>>r;

//	while(cin>>r)

	{

	for(i=0;i<46 && r>=i+2; i++)

		r -= (n[i] = i+2);

	//then, i is the length of the data

	l=i;

	for(i--; r>0 && i>=0; r--)

		n[i--]++;

	while(r-- > 0)

		n[l-1]++;

	for(i=0;n[i];i++)

		cout<<n[i]

			<<' ';

	}

	return 0;

}

