#include <algorithm>
#include <iostream>
using namespace std;

struct SparseFactorialDiv2 {

    long long getCount(long long lo, long long hi, long long divisor) {
        long long i=0;
        long long cnt = 0;
        vector<int> remain (divisor, 0);
        for (; divisor+i*i <= hi; i+=1) {
            if (remain[(i * i) % divisor] == 1) continue;
            remain[(i * i) % divisor] = 1;
            
            long long low = lo - i*i;
            if (low < 1) low = 1;
            long long high = hi - i*i;
            long long dmin = (low - 1)/ divisor;
            long long dmax = high / divisor;
            cnt += (dmax - dmin);
            cout<<"# "<<i<<" "<<dmin<<" ~ "<<dmax<<endl;
        }
        return cnt;
    }
};
