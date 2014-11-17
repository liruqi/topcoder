/* pku2014 */
#include<iostream>
using namespace std;

int max(int x, int y)
{
	return x>y ? x : y;
}

int main()
{	
   int w,a,b,x,y;
	while(cin>>w && w>0)
	{
		int at,bt;
		a = 0; b = 0;
		cin>>x>>y;
		at = x;
		bt = 0;
		while(x != -1 && y != -1)
		{
			if(a + x > w){
				at = max(a,at);
 				a = 0;
				bt += b;
				b = 0;
			}

			b = max(y,b);
			a += x;
			
			cin>>x>>y;
		}
		at = max(a,at);
		bt += b;
		cout<<at<<" x "<<bt<<endl;
	}
	return 0;
}
