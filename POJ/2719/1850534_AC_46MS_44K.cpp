#include <iostream.h>
static int t9[10] =	{1, 9, 81, 729, 6561, 59049, 531441, 4782969,	
					43046721, 387420489};
static int t0[10] =	{1, 10, 100, 1000, 10000, 100000, 1000000, 
					10000000, 100000000, 1000000000};

int n,i,s;
int main(void)
{
	while(cin>>n && n>0)
	{
		int d[10];
		for(s=0,i=0; i<10 && n>=t0[i]; i++)
		{
			d[i]=(n%t0[i+1]) / t0[i];
			d[i]=d[i]>4?d[i]-1:d[i];
			s += d[i] * t9[i];
		}

		cout<<n
			<<": "
			<<s
			<<endl;
	}
}