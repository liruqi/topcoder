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
#include <stdio.h>
using namespace std;

class FoxAndMp3 {
public:
    vector <string> playList(int);
};

vector <string> FoxAndMp3::playList(int n) {
    vector<string> can;
    char buf[32];
    for (int i=1; i<=n && i<100; i++) {
        sprintf(buf, "%d.mp3", i);
        string str (buf);
        can.push_back(str);
    }
    for (int i=100; i<=n; i*=10) {
        for (int j=0;j<100;j++) if (i+j <= n) {
            sprintf(buf, "%d.mp3", i+j);
            string str (buf);
            can.push_back(str);
        }
    }
    sort(can.begin(), can.end(), less<string>());
    vector<string> ret;
    for (int i=0; i<n && i<50; i++) {
        ret.push_back(can[i]);
    }
    return ret;
}


//Powered by [KawigiEdit] 2.0!
