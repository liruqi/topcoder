// https://www.hackerrank.com/challenges/square-subsequences
// DP
#include <iostream>
using namespace std;

int MOD = 1000000007;

int dp[2][200];
int lss(string s, string t) {
    fill(dp[1], dp[1]+t.size(), 0);
    int *cur;
    int *pre;
    for (int i=0; i<s.size(); i++) {
        cur = dp[i % 2];
        pre = dp[1 - i%2];

        fill(cur, cur+t.size(), 0);
 
        for (int j=0; j<t.size(); j++) {
            int now = pre[j];
            int p = -1;
            
            for (int k=0; k<=j; k++) if (s[i] == t[k]) { now += 1; if(k>0) now = (now + pre[k-1]) % MOD; }
            
            cur[j] = (now % MOD);
            // printf("# %d %d %d\n", i,j,now);
        }
    }
    int ret = (cur[t.size() - 1] + MOD - pre[t.size() - 1]) % MOD; 
    // cout<<"# "<<s<<" "<<t<<" : "<<cur[t.size()-1]<<"-"<<pre[t.size()-1]<<endl;
    return ret; 
}

int main() {
    int kase;
    cin >> kase;

    for (int k=0; k<(kase);k ++) {
    string s;
    cin >> s;
    int res = 0;
    for (int sl=1; sl<s.size(); sl++) {
        res += lss(s.substr(0,sl), s.substr(sl));
        res %= MOD;
    }
        printf("%d\n", res);
    }
}
