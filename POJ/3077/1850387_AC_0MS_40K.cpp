#include <iostream.h>

int n,d,h;
void main()
{
	cin>>n;
	while(n--)
	{
		cin>>d;
		if(d<10)
			;
		else if(d<100)
		{
			h=d-d%10;
			d=(d%10>4)?h+10:h;
		}
		else if(d<1000)
		{
			h=d-d%100;
			d=(d%100>44)?h+100:h;
		}
		else if(d<10000)
		{
			h=d-d%1000;
			d=(d%1000>444)?h+1000:h;
		}
		else if(d<100000)
		{
			h=d-d%10000;
			d=(d%10000>4444)?h+10000:h;
		}
		else if(d<1000000)
		{
			h=d-d%100000;
			d=(d%100000>44444)?h+100000:h;
		}
		else if(d<10000000)
		{
			h=d-d%1000000;
			d=(d%1000000>444444)?h+1000000:h;
		}
		else
		{
			h=d-d%10000000;
			d=(d%10000000>4444444)?h+10000000:h;
		}
		cout<<d<<endl;
	}

	
}