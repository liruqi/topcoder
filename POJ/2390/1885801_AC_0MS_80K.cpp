#include <iostream.h>
#include <math.h>
void main()
{
	int year,money,i;
	cin>>i>>money>>year;
	cout<<(int)((double)money * pow((double)i/100+1,year));
}