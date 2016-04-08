// http://rosettacode.org/wiki/Roman_numerals

#include <string>
#include <vector>

using namespace std;
#ifndef abs
#define abs fabs
#endif
namespace numbers {
    std::string int_to_roman(int value)
    {
        struct romandata_t { int value; char const* numeral; };
        static romandata_t const romandata[] = {
            1000, "M",
            900, "CM",
            500, "D",
            400, "CD",
            100, "C",
            90, "XC",
            50, "L",
            40, "XL",
            10, "X",
            9, "IX",
            5, "V",
            4, "IV",
            1, "I",
            0, NULL }; // end marker
        std::string result;
        for (romandata_t const* current = romandata; current->value > 0; ++current)
        {
            while (value >= current->value)
            {
                result += current->numeral;
                value  -= current->value;
            }
        }
        return result;
    }
    
    int roman_to_int(char c)
    {
        switch (c)
        {
            case 'I':  return 1;
            case 'V':  return 5;
            case 'X':  return 10;
            case 'L':  return 50;
            case 'C':  return 100;
            case 'D':  return 500;
            case 'M':  return 1000;
        }
        return 0;
    }
    
    int roman_to_int(const string& s)
    {
        int retval = 0, pvs = 0;
        for (auto pc = s.rbegin(); pc != s.rend(); ++pc)
        {
            const int inc = roman_to_int(*pc);
            retval += inc < pvs ? -inc : inc;
            pvs = inc;
        }
        return retval;
    }
    
    vector< pair<int,int> > sort_uniq_c(vector<int>& nums) { // sort | uniq -c
        vector< pair<int,int> > cnted;
        if (nums.size() == 0) {
            return cnted;
        }
        cnted.push_back(make_pair(nums[0],1));
        for (int i=1; i<nums.size(); i++) {
            pair<int,int> & top = cnted[cnted.size() - 1];
            if (top.first == nums[i]) {
                top.second += 1;
            } else {
                cnted.push_back(make_pair(nums[i],1));
            }
        }
        return cnted;
    }
    
    vector< vector<int> > unique_three_sum(vector<int>& nums, int dest) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        vector< pair<int,int> > cnted = sort_uniq_c(nums);
        for (long ci=cnted.size() - 1; ci >=0; ci--) {
            pair<int,int> cp = cnted[ci];
            if (cp.first * 3 < dest) {
                break;
            }
            if (cp.first * 3 == dest) {
                if (cp.second >= 3) {
                    vector<int> can;
                    can.push_back(cp.first);
                    can.push_back(cp.first);
                    can.push_back(cp.first);
                    res.push_back(can);
                }
                break;
            }
            
            int sum = cp.first * 2;
            if (cp.second >= 2) {
                for (long ai=ci - 1; ai >= 0; ai--) {
                    if (sum + cnted[ai].first == dest) {
                        vector<int> can;
                        can.push_back(cnted[ai].first);
                        can.push_back(cp.first);
                        can.push_back(cp.first);
                        res.push_back(can);
                        break;
                    }
                }
            }
            sum = cp.first;
            int bdest = dest - sum;
            for (long bi = ci - 1; bi >= 0; bi --) {
                pair<int,int> bp = cnted[bi];
                if (bp.first * 2 < bdest) {
                    break;
                }
                if (bp.first * 2 == bdest) {
                    if (bp.second >= 2) {
                        vector<int> can;
                        can.push_back(bp.first);
                        can.push_back(bp.first);
                        can.push_back(cp.first);
                        res.push_back(can);
                    }
                    break;
                }
                int cdest = bdest - bp.first;
                for (long ai=bi - 1; ai >= 0; ai--) {
                    if (cnted[ai].first == cdest) {
                        vector<int> can;
                        can.push_back(cnted[ai].first);
                        can.push_back(bp.first);
                        can.push_back(cp.first);
                        res.push_back(can);
                        break;
                    }
                }
            }
        }
        return res;
    }
    
    int closest_three_sum(vector<int>& nums, int dest) {
        sort(nums.begin(), nums.end());
        long res = INT_MAX;
        vector< pair<int,int> > cnted = sort_uniq_c(nums);
        for (long ci=cnted.size() - 1; ci >=0; ci--) {
            pair<int,int> cp = cnted[ci];
            if (cp.second >= 3) {
                if (abs(cp.first * 3 - dest) < abs(res - dest)) {
                    res = cp.first * 3;
                }
            }
            if (cp.second >= 2) {
                for (long ai=ci - 1; ai >= 0; ai--) {
                    if (abs(cp.first * 2 + cnted[ai].first - dest) < abs(res - dest)) {
                        res = cp.first * 2 + cnted[ai].first;
                    }
                }
            }
            
            for (long bi = ci - 1; bi >= 0; bi --) {
                pair<int,int> bp = cnted[bi];
                if (bp.second >= 2) {
                    if (abs(bp.first * 2 + cp.first - dest) < abs(res - dest)) {
                        res = bp.first * 2 + cp.first;
                    }
                }
                
                for (long ai=bi - 1; ai >= 0; ai--) {
                    if (abs(bp.first + cp.first + cnted[ai].first - dest) < abs(res - dest)) {
                        res = bp.first + cp.first + cnted[ai].first;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        return numbers::int_to_roman(num);
    }
    int romanToInt(string s) {
        return numbers::roman_to_int(s);
    }
    
    vector<vector<int> > threeSum(vector<int>& nums) {
        return numbers::unique_three_sum(nums, 0);
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        return numbers::closest_three_sum(nums, target);
    }
};

