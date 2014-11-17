// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/


#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> lastpos;
        int start=0;
        int ret=0;
        for (int i=0; i<s.size(); i++) {
            int ch = s[i];
            map<int,int>::iterator it = lastpos.find(ch);
            if (it == lastpos.end() || it->second < start) {
                ret = max(ret, i - start + 1);
            } else {
                string res(s.begin() + start, s.begin() + i);
                cout << res << endl;
                start = it->second + 1;
            }
            lastpos[ch] = i;
        }
        return ret;
    }
};

int main () {
    Solution s ;

    cout<< s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;   
}
