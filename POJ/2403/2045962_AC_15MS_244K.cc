#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int m,n;
	while(cin >> m >> n)
    {
		map<string,int> table;
		string buf;
        int v, sum;
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