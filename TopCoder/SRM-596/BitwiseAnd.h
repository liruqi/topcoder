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

class BitwiseAnd {
public:
    vector<long long> lexSmallest(vector<long long>, int);
};

vector<long long> BitwiseAnd::lexSmallest(vector<long long> subset, int N) {
    for (int i=0;i< subset.size();i++) for (int j=i+1;j<subset.size(); j++) {
        long long x=subset[i];
        long long y=subset[j];
        if ((x&y) == 0) {
            cout<<"#"<<x<<" & "<<y<<"\n";
            return vector<long long>(0);
        }
        for (int k=j+1;k<subset.size();k++) if (x&y&subset[k]) {
        cout<<"#"<<x<<" & "<<y<<" & "<<subset[k]<<"\n";
        return vector<long long>(0);
        }
    }
    if (N == subset.size()) return subset;
    int bits = N-1-subset.size();
    long long next = 0;
    vector<bool> matched (subset.size(), 0);
    for (int i=0; i<60; i++) {
        vector<int> bset(0);
        for (int j=0;j<subset.size(); j++) {
            if (subset[j] & (1LL<<i)) bset.push_back(j);
        }
        if (bset.size() == 0) {
            if (bits > 0) {bits-=1; next+=(1LL<<i);}
        } else if (bset.size()==1) {
            if (!matched[bset[0]]) {
                matched[bset[0]] = 1;
                next+=(1LL<<i);
            }
        }
    }
    subset.push_back(next);
    sort(subset.begin(), subset.end());
    return lexSmallest(subset, N);
}


//Powered by [KawigiEdit] 2.0!
