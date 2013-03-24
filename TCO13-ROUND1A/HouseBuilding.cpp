#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class HouseBuilding {
public:
	int getMinimum(vector <string>);
	int effort(vector <string> area, int dst) {
		int res = 0;
		for (int i=0;i<area.size();i++) {
		string line = area[i];
		for (int j=0;j<line.size();j++) {int delta=(line[j] - dst); if (delta>1) res+=(delta-1); else if(delta<0) res+=-delta;}
		}
		cout<<"# " <<dst - '0'<<" "<<res<<endl;
		return res;
	}
};

int HouseBuilding::getMinimum(vector <string> area) {
	
	int middle = '0';
	int res = effort(area, middle);
	for(;middle <= '9';middle++)
		res <?= effort(area, middle);
	return res;
}


//Powered by [KawigiEdit] 2.0!
