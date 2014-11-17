#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ISBN;
	cin >> ISBN;
	static int index = ISBN.find("?");
	int all=0, i, j, ans=-1;
	for(j = 10,i=0; i<ISBN.size(); i++,j--)
	{
		if(i!=index)
		{
			if(ISBN[i]=='X' && i==9) 
				all+=10;
			else 
				all += int(ISBN[i]-'0') * j;
		}
	}
	for(i=0;i<10; i++)
	{
		if( (all + i*(10-index))%11 == 0)
		{ ans = i;  break;	}
	}
	if(index == 9 && all % 11 == 1)
		cout << "X" << endl;
	else 
		cout << ans << endl;
	return 0;
}