#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int m,n;
	string buf;
	int v, sum;
	while(cin >> m >> n)
    {
		map<string,int> table;
		while(m--)
        {
            cin >> buf >> v; 
            table[buf] = v;
        }
		while(n--)
        {
			sum = 0;
			while(cin >> buf && buf != ".")
                sum += table[buf];
			cout << sum << endl;
		}
	}
	return 0;
}
