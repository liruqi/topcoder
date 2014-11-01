// Solution for  
// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1279
// Author: liruqi@gmail.com

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSZ 100000

int wsz[MAXSZ];
int N,M;


int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> wsz[i];
    }
    
    int minsz = wsz[0];
    for (int i=1; i<N; i++) {
        minsz = min(minsz, wsz[i]);
        wsz[i] = minsz;
    }

    int right = N;
    int cnt = 0;
    for (int i=0; i<M; i++) {
        if (right <= 0) break;
        int psz; cin>> psz;
        while(right > 0) {
            right --;
            if (wsz[right] >= psz) {
                cnt ++;
                break;
            }
        }
    }
    cout<< cnt  << endl;
}
