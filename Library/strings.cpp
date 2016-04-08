
#include <string>

namespace strings {
    std::string longest_common_prefix(std::string f, std::string s) {
        int i=0;
        for (; i<f.length() && i<s.length() && f[i]==s[i]; i++);
        return f.substr(0, i);
    }

    std::string longest_common_prefix(vector<std::string>& strs) {
        int i=1;
        if (strs.size() == 0) return "";
        std::string result = strs[0];
        for (; i<strs.size(); i++)
            result = longest_common_prefix(result, strs[i]);
        return result;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return strings::longest_common_prefix(strs);
    }
};
