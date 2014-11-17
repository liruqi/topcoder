
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    char pattern[1024];
    int fb[1024];
    int kmp(string t, char* p, int psize) {
        if (psize == 0) return 0;
        fb[0] = 0; fb[1] = 0;
        // cout<<"$ " <<p.size() << " => " <<p<<endl; 
        for(int i=2;i<=psize;i++) {
            int l = fb[i-1];
            while(l >= 0) {
                if (p[i - 1] == p[l]) {
                    //  fb.push_back(l + 1);
                    fb[i] = l + 1;
                    // cout<<"# "<< i <<" " << l + 1<<endl;
                    break;
                }
                if (l == 0) {
                    // fb.push_back(0);
                    fb[i] = 0;
                    // cout<<"# "<< i <<" " << 0 <<endl;
                    break;
                }
                l = fb[l];
            }
        }
        cout<<"$$ " <<p<<endl; 
        int matchp = 0;
        int ret = 0;
        int ti = 0;
        while(ti < t.size()) {
            if (t[ti] == p[matchp]) {
                ti ++; matchp++; ret = max(ret, matchp);
                if (matchp >= psize) return matchp;
            } else if (matchp > 0) {
                matchp = fb[matchp];
            } else {
                ti ++;
            }
        }
        return ret;
    }

    int cmp(int sl, int sr, int sz) {
        int ret = 0;
        while(sl >=0 && sr < sz) {
            if (pattern[sl] == pattern[sr]) {sl --; sr++; ret++;} else break;
        }
        return ret;
    }

    string longestPalindrome(string s) {
        copy(s.begin(), s.end(), pattern);
        int sz = 0;
        int p = 0;
        
        for (int i=0; i<s.size(); i++) {
            
            int l = cmp(i, i, s.size());
            // cout<<"## "<< i << " " << l <<endl;
            if (2*l - 1 > sz) {
                sz = 2*l - 1;
                p = i - (l - 1);
            }
            
            l = cmp(i, i+1, s.size());
            if (2*l > sz) {
                sz = 2 * l;
                p = i - (l - 1);
            }
        }
        // cout<<"# "<< p << " " << sz<<endl;
        string ret(s.begin() + p, s.begin() + p + sz);
        return ret;
    }
};

int main (int argc, char* argv[]) {
    Solution s ;
    cout<< s.longestPalindrome(argc > 1 ? argv[1] : "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}
