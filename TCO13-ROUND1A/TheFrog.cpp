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


class TheFrog {
public:
	double getMinimum(int, vector <int>, vector <int>);
	double xMax, xMin;
	vector <pair<int,int> > LR;
	
	int n, DD;

	int intCheckX(int numerator , int denominator) {
		int i=0;
		
		for(int p=0; p<DD * denominator; p+=numerator) {
			if(p<=LR[i].first * denominator) {
				//cout<<"#gogogo " <<p<<" ("<<LR[i].first<<", "<<LR[i].second<<endl; 
				p = (LR[i].first * denominator / numerator) * numerator;
				continue;
			}
			while(p >= LR[i].first * denominator && p>=LR[i].second * denominator && i<n) {
				//cout<<"#pass " <<p<<" ("<<LR[i].first<<", "<<LR[i].second<<endl; 
				i++;
			}
			if (i>=n) { break;}
			if (p > LR[i].first * denominator && p<LR[i].second*denominator) {
				//cout<<"#failed " <<numerator<<" / "<<denominator<<" ("<<LR[i].first<<", "<<LR[i].second<<endl; 
				return 0;
			}
		}
		double x = (double)numerator / denominator;
		//cout<<"#passed " <<x<<endl; 
		if (x<xMax) xMax = x;
		return 1;
	}
	void findX(int p) {
		if (p<=0) return;
		double x = p;
		//cout<<"# findX: "<<x<<endl;
		if (intCheckX(p,1)) {
			//cout<<"# findX: "<<x<<" / "<<" start:"<<int(x/xMin)<<endl;
			for(int i=(x/xMin); i>=1; i--) {
				if (x/i >= xMax) return;
				
				if (intCheckX(p,i)) {
					//cout<<"#pass " <<x<<" ("<<i<<")"<<endl;
					return;
				}
			}
		}
	}
};

double TheFrog::getMinimum(int D, vector <int> L, vector <int> R) {
	int biggestHole = 0;
	DD = D;
	n = L.size();
	LR.clear();
	for (int i=0; i<n; i++) {biggestHole = max(biggestHole, R[i]-L[i]); LR.push_back(make_pair(L[i],R[i]));}
	sort(LR.begin(), LR.end());
	xMax = D;
	xMin = biggestHole;
	//cout<<"# xMin: "<<xMin<<endl;
	for (int i=0; i<n; i++) {
		findX(L[i]);
		findX(R[i]);
	}
	
	return xMax;
}



//Powered by [KawigiEdit] 2.0!
