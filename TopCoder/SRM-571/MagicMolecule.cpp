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

class MagicMolecule {
public:
    int maxMagicPower(vector <int>, vector <string>);
    vector <int> mp;
    int n, minselect, maxremove;
    vector<long long> mask;

int dfs(int p, long long m) {
    
    if (__builtin_popcountll(m) < minselect) return -1;
    //cout<<"# "<<m<<" position: "<<p<<endl;
    if (p>=n) {
        int sum = 0;
        int cnt = 0;
        for(int i=0; i<n; i++) if ((1LL<<i) & m) {cnt++; sum+=mp[i];}
        return sum;
    }
    
    if (((1LL<<p) & m) == 0) return dfs(p+1,m);
    
    if ((mask[p] & m) == m) {
    //cout<<"# "<<m<<" full match: "<<p<<" mask:"<<mask[p]<<endl;
        return dfs(p+1, m);
    }
    return max(
        dfs(p+1, m - (1LL<<p)),
        dfs(p+1, m & mask[p])
    );
}
};


int MagicMolecule::maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
    mp = magicPower;
    n=magicPower.size();
    minselect=0;
    while (minselect*3 < 2*n) minselect+=1;
    maxremove = n - minselect;
    mask.clear();
    
    long long m = 0;
    int j;
    for (int i=0; i<n; i+=1) {
        m = 0;
        for (j=0;j<n;j++) {
            if (magicBond[i][j] == 'Y' || i==j) m += (1LL<<j);
        }
        mask.push_back(m);
        cout<<"# mask "<<magicBond[i]<<" : "<<m<<endl;
    }
    return dfs(0, (1LL<<n) - 1);
    
    // __builtin_popcountll 
}


//Powered by [KawigiEdit] 2.0!