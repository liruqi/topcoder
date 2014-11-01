// Solution for 大鱼吃小鱼 
// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1289
// Author: liruqi@gmail.com

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSZ 100000

int fsz[MAXSZ], fdir[MAXSZ];
int lmax[MAXSZ], rmax[MAXSZ]; // max size to left & right, current position not included
int N;

int fishfish(int* sz, int* dir) {
    
    int lmaxsz = 0;
    int r=0;
    for (int i=0; i<N; i++) {
        
        if (dir[i] == 0) {
            if (sz[i] > lmaxsz) {
                r++;
                // cout << "# "<< i << " < " << endl;
                lmaxsz = 0; 
            }
        } else {
            lmaxsz = max(lmaxsz, fsz[i]);
        }
    }
    // cout << "# "<< endl;
    return r;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> fsz[i] >> fdir[i];
    }
    
    int cnt = fishfish(fsz, fdir);
    reverse(fsz, fsz + N);
    reverse(fdir, fdir + N);

    for (int i=0; i<N; i++) {
        fdir[i] = 1 - fdir[i];
    }
    
    cout<< cnt + fishfish(fsz, fdir) << endl;
}
