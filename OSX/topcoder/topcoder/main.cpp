// http://rosettacode.org/wiki/Roman_numerals

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <numeric>
#include <stack>
#include <queue>
#include "math.h"
#include "assert.h"

using namespace std;

#ifndef abs
#define abs(x) (((x) > 0) ? (x) : (-(x)))
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
        sort(nums.begin(), nums.end());
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
    
    vector< vector<int> > _unique_three_sum(vector<pair<int,int> > & cnted, int dest) {
        vector< vector<int> > res;
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
    
    vector< vector<int> > unique_three_sum(vector<int>& nums, int dest) {
        vector< pair<int,int> > cnted = sort_uniq_c(nums);
        return _unique_three_sum(cnted, dest);
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
    
    
    /* cnted 是一个递增的数组
     * pair first 为数值；pair sencond 为数量(假设均>=1)
     */
    vector< vector<int> > _unique_sum_fixed_size(vector<pair<int,int> >& cnted, int startIdx, int dest, int depth) {
        vector< vector<int> > res;
        
        pair<int,int> & cp = cnted[startIdx];
        if (depth == 0) {
            if (dest == 0) {
                vector<int> can;
                res.push_back(can);
            }
            return res;
        }
        if (startIdx >= cnted.size()) return res;
        if (depth == 1) {
            int endIdx = cnted.size() - 1;
            while (startIdx <= endIdx) {
                int m = (startIdx + endIdx) / 2;
                int d = cnted[m].first - dest;
                if (d == 0) {
                    vector<int> can;
                    can.push_back(dest);
                    res.push_back(can);
                    break;
                } else if (d < 0) {
                    startIdx = m + 1;
                } else {
                    endIdx = m - 1;
                }
            }
            
            return res;
        }
        if (cp.first * depth > dest) {
            return res;
        }
        if (cnted[cnted.size() - 1].first * depth < dest) {
            return res;
        }
        for (int c= min(cp.second, depth); c>=0; c--) {
            vector< vector<int> > subres = _unique_sum_fixed_size(cnted, startIdx + 1, dest - cp.first * c, depth - c);
            for (int subi=0; subi<subres.size(); subi++) {
                vector<int> can = subres[subi];
                can.insert(can.begin(), c, cp.first);
                res.push_back(can);
            }
        }
        
        return res;
    }
    
    vector< vector<int> > unique_four_sum(vector<int>& nums, int target) {
        vector< pair<int,int> > cnted = numbers::sort_uniq_c(nums);
        return numbers::_unique_sum_fixed_size(cnted, 0, target, 4);
    }
    
    /* cnted 是一个递增的数组
     * pair first 为数值；pair sencond 为数量(假设均>=1)
     * 无长度限制
     */
    vector< vector<int> > _unique_sum(vector<pair<int,int> >& cnted, int startIdx, int dest) {
        vector< vector<int> > res;
        if (dest == 0) {
            vector<int> can;
            res.push_back(can);
            return res;
        }
        
        if (startIdx >= cnted.size()) return res;
        pair<int,int> & cp = cnted[startIdx];
        if (cp.first > dest) return res;
        for (int c= cp.second; c>=0; c--) {
            vector< vector<int> > subres = _unique_sum(cnted, startIdx + 1, dest - cp.first * c);
            for (int subi=0; subi<subres.size(); subi++) {
                vector<int> can = subres[subi];
                can.insert(can.begin(), c, cp.first);
                res.push_back(can);
            }
        }
        
        return res;
    }
    
    int decimal_digits_set(int n) {
        int s = 0;
        while (n > 0) {
            s |= (1 << (n % 10));
            n /= 10;
        }
        return s;
    }
    
    vector<int> decimal_digits(int n) {
        vector<int> dgts;
        while (n > 0) {
            dgts.push_back(n % 10);
            n /= 10;
        }
        return dgts;
    }
    
    // range: [left, right]
    int max_decimal_digits_set_intersection(int left,int right) {
        map<int,int> cnt[11];
        
        for (int i = left; i<=right; i++) {
            int s = decimal_digits_set(i);
            map<int,int> & mp = cnt[__builtin_popcount(s)];
            map<int, int>::iterator it = mp.find(s);
            if (it == mp.end()) {
                mp[s] = 1;
            } else {
                it->second += 1;
            }
        }
        
        for (int i=10; i>0; i--) {
            map<int,int> & mp = cnt[i];
            if (mp.size() == 0) {
                continue;
            }
            for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
                if (it->second > 1) {
                    return i;
                }
                map<int,int> & pmp = cnt[i - 1];
                int s = it->first;
                for (int i=1; i>=0 && i<=s; i *= 2) {
                    if (s & i) {
                        map<int, int>::iterator pit = pmp.find(s - i);
                        if (pit == pmp.end()) {
                            pmp[s - i] = 1;
                        } else {
                            pit->second += 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    size_t dump(vector<int> lst) {
        for (int v : lst) { cout<<v<<" "; }
        cout<<" # len="<<lst.size()<<endl;
        return lst.size();
    }
    
    // find longest increasing prefix
    // return prefix
    vector< pair<int,int> > inc_prefix_uniq_c(vector<int>& nums) {
        vector< pair<int,int> > cnted;
        if (nums.size() == 0) {
            return cnted;
        }
        cnted.push_back(make_pair(nums[0],1));
        for (int i=1; i<nums.size(); i++) {
            pair<int,int> & top = cnted[cnted.size() - 1];
            if (top.first == nums[i]) {
                top.second += 1;
            } else if (top.first > nums[i]) {
                cnted.push_back(make_pair(nums[i],1));
            } else {
                break;
            }
        }
        return cnted;
    }
    // find longest increasing prefix
    // return prefix length
    size_t inc_prefix(vector<int>& nums) {
        vector< pair<int,int> > cnted;
        if (nums.size() == 0) {
            return 0;
        }
        cnted.push_back(make_pair(nums[0],1));
        for (size_t i=1; i<nums.size(); i++) {
            pair<int,int> & top = cnted[cnted.size() - 1];
            if (top.first == nums[i]) {
                top.second += 1;
            } else if (top.first < nums[i]) {
                cnted.push_back(make_pair(nums[i],1));
            } else {
                return i;
            }
        }
        return nums.size();
    }
    
    /*
     Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
     
     For example, given the array [2,3,1,2,4,3] and s = 7,
     the subarray [4,3] has the minimal length under the problem constraint.
     return 2
     */
    size_t length_of_min_sub_array_greater_or_equal(int s, vector<int>& nums) {
        size_t start = 0;
        size_t end = 0;
        int can = 0;
        size_t ret = nums.size();
        while (start <= end && start<nums.size() && end < nums.size()) {
            while (can < s) {
                can += nums[end];
                end += 1;
                if (end >= nums.size()) { if (can < s && start == 0) return 0; break;}
            }
            while (can - nums[start] >= s) {
                can -= nums[start];
                start += 1;
            }
            cout<< start << end << endl;
            ret = min(end - start, ret);
            can -= nums[start];
            start += 1;
        }
        return ret;
    }
    
    int trapping_rain_water(vector<int> &height, int base, int next) {
        int begin = -1;
        int sum = 0;
        for (int i=0; i<height.size(); i++) {
            if (height[i] >= base) {
                if (begin < 0) {
                    begin = i + 1;
                } else {
                    sum += (i - begin);
                    begin = i + 1;
                }
            }
        }
        return sum * (next - base);
    }
};

namespace maths {
#define MATH_MAX_INT 1000000000
#define MATH_SQRT_MAX_INT 31623
//    bool primes[MATH_SQRT_MAX_INT];
//    int primes_cnt;
    bool is_prime(int x) {
        for (int i=2; i*i <= x; i++) {
            if (x % i == 0) return false;
        }
        return x > 1;
    }
    int sum_of_decimal_digits_squares(int n) {
        int s = 0;
        while (n > 0) {
            int d =(n % 10);
            s += d*d;
            n /= 10;
        }
        return s;
    }
};

// single list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodeCompare {
    bool operator()(ListNode * p, ListNode * q){
        return p->val > q->val;
    }
};

namespace lists {
    size_t size(ListNode *h) {
        size_t s = 0;
        while (h) {s+=1; h=h->next;}
        return s;
    }
    int remove(ListNode **paddr) {
        ListNode *p = *paddr;
        if (p==NULL) return 0;
        *paddr = p->next;
        // free(p)
        return 1;
    }
    ListNode ** get(ListNode **it, size_t k) {
        for (;k>0;k--) {
            it = & ((*it)->next);
        }
        return it;
    }
    size_t dump(ListNode *h) {
        size_t s = 0;
        while (h) {s+=1; cout<<h->val<<" "; h=h->next;}
        cout<<" # len="<<s<<endl;
        return s;
    }
    
    ListNode * merge_inc_list(ListNode *l1, ListNode *l2) {
        if (! l1) return l2;
        if (! l2) return l1;
        
        ListNode *h = 0;
        ListNode *it = NULL;
        if (l1->val < l2->val) {
            h = l1; l1 = l1->next;
        } else {
            h = l2; l2 = l2->next;
        }
        it = h;
        while (l1 || l2) {
            if (! l1) {
                it->next = l2;
                return h;
            }
            if (! l2) {
                it->next = l1;
                return h;
            }
            if (l1->val < l2->val) {
                it -> next = l1; it = l1; l1 = l1->next;
            } else {
                it -> next = l2; it = l2; l2 = l2->next;
            }
        }
        return h;
    }
    ListNode* merge_inc_lists(vector<ListNode*>& lists) {
        ListNode *h = NULL;
        ListNode *it = NULL;
        priority_queue<ListNode*, vector<ListNode*>, ListNodeCompare> pq;
        for (ListNode * lh : lists) {
            if (lh) {
                pq.push(lh);
            }
        }
        while (pq.size()) {
            if (h) {
                it->next = pq.top();
                it = it->next;
            } else {
                it = pq.top();
                h = it;
            }
            pq.pop();
            if (it && it->next) {
                pq.push(it->next);
            }
        }
        return h;
    }
    /*
     Swap two list nodes
     
     o -> p -> q -> r
     o -> q@ p -> r
     o -> q -> p -> r
     
     handled case p->next == q
     case q->next == p is not handled
     */
    pair<ListNode *, ListNode *> swap(ListNode **paddr, ListNode **qaddr) {
        if (! paddr || !qaddr) {
            ListNode *nil = NULL;
            return make_pair(nil,nil);
        }
        ListNode *p = (*paddr);
        ListNode *q = (*qaddr);
        std::swap(p->next, q->next);
        if (q->next == q) {
            q->next = p;
            *paddr = q;
        } else {
            std::swap(*paddr, *qaddr);
        }
        return make_pair(q, p);
    }
};

#define STRINGS_CHARSET_SZ 256
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
    
    bool is_closed_parentheses(string s, char *mp) {
        stack<char> stk;
        for(char ch : s) {
            if (mp[ch] > 0) {
                if (stk.size() > 0 && mp[ch]  == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(ch);
            }
        }
        
        return (stk.size() == 0);
    }
    
    // mp: char to int
    long to_long(string s, int *mp, long base) {
        long ret = 0;
        for(char ch : s) {
            ret = mp[ch] + ret * base;
        }
        return ret;
    }
    
    long excel_column_to_long(string s) {
        int mp[STRINGS_CHARSET_SZ];
        memset(mp, 0, sizeof(mp));
        for (char ch='A'; ch <='Z'; ch++) mp[ch] = ch - 'A' + 1;
        return to_long(s, mp, 26);
    }
    
    // mp: int to char
    string from_long(int n, char *mp, long base, int zero) {
        vector< pair<long,long> > plist;
        long last = 0;
        long powr = 1;
        string s;
        // A -> 1 zero
        // AA -> 27 zero + base
        // AAA ->
        for (int len = 1; last < n; len++) {
            s.push_back (mp[zero]);
            last = excel_column_to_long(s);
            plist.push_back(make_pair(last, powr));
            powr *= base;
        }
        
        string ret;
        for (int idx = plist.size() - 1; idx>=0; idx--) {
            if (plist[idx].first > n) continue;
            long val = n - plist[idx].first;
            long dgt = (val / plist[idx].second);
            char ch = mp[dgt + zero];
            ret.push_back(ch);
            n -= (dgt + zero) * plist[idx].second;
        }
        return ret;
    }
    
    string long_to_excel_column(long n) {
        char mp[STRINGS_CHARSET_SZ];
        memset(mp, 0, sizeof(mp));
        for (int ch=1; ch <=26; ch++) mp[ch] = ch + 'A' - 1;
        return from_long(n, mp, 26, 1);
    }
};

struct ExploringNumbers {
    int numberOfSteps(int n) {
        set<int> numbers;
        int it = n;
        while (! maths::is_prime(it)) {
            if (numbers.find(it) == numbers.end()) {
                cout << "# " << it << endl;
                numbers.insert(it);
                if (numbers.size() >= n) return -1;
                it = maths::sum_of_decimal_digits_squares(it);
            } else {
                return -1;
            }
        }
        return numbers.size() + 1;
    }
};

/*
 Vasa is a shopkeeper in the small town Deronje. Currently, there are some items for sale in his store. The price of each item is a positive integer. You are given these prices in the vector <int> A. Each item has a price tag.
 Vasa has just learned that a very rich shopper is going to visit his store. Therefore, Vasa wants to alter some of the price tags to make the items in his store more expensive.
 Vasa has a collection of stickers. Each of those stickers contains a single digit between 1 and 9, inclusive. Note that he has no stickers with zeros. You are given the description of Vasa's stickers in the vector <int> D. For each i between 1 and 9, inclusive, Vasa has D[i-1] stickers with the digit i.
 Vasa can take any sticker and use it to replace any digit on any price tag. However, there is no extra room on the price tags, so he cannot add new digits, he can only replace existing ones.
 Compute and return the maximum total cost of items in Vasa's store after he applies some (possibly none, possibly all) of his stickers to the current price tags.
 */
struct ReplacingDigit {
    int getMaximumStockWorth(vector <int> A, vector <int> D) {
        vector< vector<int> > digits[8];
        for (int num : A) {
            vector<int> dgts = numbers::decimal_digits(num);
            digits[dgts.size()].push_back(dgts);
        }
        int res = std::accumulate(A.begin(), A.end(), 0);
        
        int pi = 6;
        int p = 1000000;
        for (; pi>=0; p/=10, pi-=1) {
            
            int ncnts[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int sz=pi+1; sz<=7; sz+=1) {
                for (int i=0; i<digits[sz].size(); i++)
                    ncnts[ digits[sz][i][pi]] += 1;
            }
            for(int j=0; j<=9; j++) {
                for (int i=D.size() - 1; i>=0; i--) {
                    if (D[i] == 0) {
                        continue;
                    }
                    int dgt = i + 1;
                    if (dgt <= j) break;
                    int cnt = min(D[i], ncnts[j]);
                    D[i] -= cnt;
                    ncnts[j] -= cnt;
                    res += p * (dgt - j) * cnt;
                }
            }
        }

        return res;
    }
};



#define ALPHABETS 26

using namespace std;

class TrieNode
{
public:
    TrieNode * parent;
    TrieNode * children[ALPHABETS];
    vector<int> occurrences;
};

class Trie
{
public:
    TrieNode * root;
    
    Trie() {
        root = (TrieNode *) calloc(1, sizeof(TrieNode));
    }
    
    // Inserts a word 'text' into the Trie Tree
    // 'trie_tree' and marks it's occurence as 'index'.
    TrieNode * insert(char* text, int occurrence)
    {
        // Converting the input word 'text'
        // into a vector for easy processing
        TrieNode * temp = root;
        
        while (*text) {
            int idx = *text - 'a';
            if (temp->children[idx] == NULL) {
                // There is no node in 'trie_tree' corresponding to this alphabet
                
                // Allocate using calloc(), so that components are initialised
                temp->children[idx] =
                (TrieNode *) calloc(1, sizeof(TrieNode));
                temp->children[idx]->parent = temp; // Assigning parent
            }
            
            temp = temp->children[idx];
        }
        temp->occurrences.push_back(occurrence);      //Mark the occurrence of the word
        return temp;
    }
    
    TrieNode * insert(string text, int occurrence)
    {
        // Converting the input word 'text'
        // into a vector for easy processing
        TrieNode * temp = root;
        
        for (char ch : text) {
            int idx = ch - 'a';
            if (temp->children[idx] == NULL) {
                // There is no node in 'trie_tree' corresponding to this alphabet
                
                // Allocate using calloc(), so that components are initialised
                temp->children[idx] =
                (TrieNode *) calloc(1, sizeof(TrieNode));
                temp->children[idx]->parent = temp; // Assigning parent
            }
            
            temp = temp->children[idx];
        }
        temp->occurrences.push_back(occurrence);      //Mark the occurrence of the word
        return temp;
    }
    
    // Prints the 'trie_tree' in a Pre-Order or a DFS manner
    // which automatically results in a Lexicographical Order
    void lexicographPrint(TrieNode * trie_tree, vector<char> printUtilVector)
    {
        int i;
        bool noChild = true;
        
        vector<int>::iterator itr = trie_tree->occurrences.begin();
        
        for (i = 0; i < ALPHABETS; ++i) {
            if (trie_tree->children[i] == NULL) {
                continue;
            } else {
                noChild = false;
                printUtilVector.push_back('a' + i);    // Select a child
                
                // and explore everything associated with the cild
                lexicographPrint(trie_tree->children[i], printUtilVector);
                printUtilVector.pop_back();
                // Remove the alphabet as we dealt
                // everything associated with it
            }
        }
        
        if (trie_tree->occurrences.size() != 0) {
            // Condition trie_tree->occurrences.size() != 0,
            // is a neccessary and sufficient condition to
            // tell if a node is associated with a word or not
            
            vector<char>::iterator itr = printUtilVector.begin();
            
            while (itr != printUtilVector.end()) {
                printf("%c", *itr);
                ++itr;
            }
            printf(" -> @ index -> ");
            
            vector<int>::iterator counter = trie_tree->occurrences.begin();
            // This is to print the occurences of the word
            
            while (counter != trie_tree->occurrences.end()) {
                printf("%d, ", *counter);
                ++counter;
            }
            
            printf("\n");
        }
        
        printUtilVector.pop_back();
    }
    
    // Searches for the occurence of a word in 'trie_tree',
    // if not found, returns NULL,
    // if found, returns poniter pointing to the
    // last node of the word in the 'trie_tree'
    TrieNode * searchWord(char * text)
    {
        // Functions very similar to insert() function
        TrieNode * temp = root;
        
        while (* text) {
            int idx = *text - 'a';
            if (temp->children[idx]) {
                temp = temp->children[idx];
            } else {
                return NULL;
            }
        }
        return (* text) ? NULL : temp;
    }
    
    // Searches the word first, if not found, does nothing
    // if found, deletes the nodes corresponding to the word
    void removeWord(char * word)
    {
        TrieNode * temp = searchWord(word);
        
        if (temp == NULL) {
            // Word not found
            return;
        }
        
        temp->occurrences.pop_back();    // Deleting the occurence
        
        // 'noChild' indicates if the node is a leaf node
        
        int childCount = 0;
        // 'childCount' has the number of children the current node
        // has which actually tells us if the node is associated with
        // another word .This will happen if 'childCount' >= 2.
        int i;
        
        // Checking children of current node
        for (i = 0; i < ALPHABETS; ++i) {
            if (temp->children[i] != NULL) {
                ++childCount;
            }
        }
        
        if (childCount > 0) {
            // The node has children, which means that the word whose
            // occurrence was just removed is a Suffix-Word
            // So no more nodes have to be deleted
            return;
        }
        
        // todo: free memory,
        // reserve allocated memory for further use.
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
    
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        return numbers::unique_four_sum(nums, target);
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t sz = lists::size(head);
        size_t k = sz - n;
        ListNode **it = lists::get(& head, k);
        lists::remove(it);
        return head;
    }

    string longestCommonPrefix(vector<string>& strs) {
        return strings::longest_common_prefix(strs);
    }
    bool isValid(string s) {
        char mp[STRINGS_CHARSET_SZ];
        memset(mp, 0, sizeof(mp));
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        
        return strings::is_closed_parentheses(s, mp);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return lists::merge_inc_list(l1,l2);
    }
    ListNode* mergeKListsBruteforce(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        for (ListNode* lst : lists) {
            if (res) {
                res = lists::merge_inc_list(res, lst);
            } else {
                res = lst;
            }
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return lists::merge_inc_lists(lists);
    }
    ListNode* swapPairs(ListNode* head) {
        if ((! head) || (! head->next)) {
            return head;
        }
        ListNode *ret = NULL;
        ListNode **it = & head;
        while ((*it) && (*it)->next) {
            pair<ListNode *, ListNode *> p = lists::swap(it, &((*it)->next));
            if (! ret) ret = p.first;
            it = & (p.second->next);
#if DEBUG
            lists::dump(ret);
#endif
        }
        return ret;
    }
    string convertToTitle(int n) {
        return strings::long_to_excel_column(n);
    }
    vector<int> cnt;
    int charcnt[ALPHABETS];
    int wordslen;
    vector<int> findSubstring(string s, vector<string>& words) {
        Trie trie;
        int id = 0;
        cnt.clear();
        wordslen = 0;
        fill(charcnt, charcnt+ALPHABETS, 0);
        for (string w : words) {
            TrieNode *nd = trie.insert(w, id);
            id ++;
            cnt.push_back(0);
            cnt[nd->occurrences[0]] += 1;
            for (char ch : w) {
                wordslen += 1;
                charcnt[ch - 'a'] += 1;
            }
        }
        cout << s.size() << endl;
        vector<int> res;
        int subcnt[ALPHABETS];
        fill(subcnt, subcnt+ALPHABETS, 0);
        for (int i=0; i<wordslen; i++) {
            subcnt[s[i] - 'a'] += 1;
        }
        set<string> bad;
        
        for (int i=0; i+wordslen <=s.size(); i++) {
            if (memcmp(subcnt, charcnt, sizeof(charcnt)) == 0) {
                vector<int> rcnt = cnt;
                string can = s.substr(i, wordslen);
                if (bad.find(can) != bad.end()) {
                    continue;
                }
                if (findMatch(can, trie, rcnt)) {
                    res.push_back(i);
                } else {
                    bad.insert(s.substr(i, wordslen));
                }
            }
            subcnt[s[i] - 'a'] -= 1;
            if (i + wordslen >= s.size()) {
                break;
            }
            subcnt[s[i + wordslen] - 'a'] += 1;
        }
        return res;
    }
    
    bool findMatch(string s, Trie trie, vector<int> & rcnt) {
        TrieNode *it = trie.root;
        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            it = it->children[ch - 'a'];
            if (! it) {
                return false;
            }
            if (it->occurrences.size() == 0) {
                continue;
            }
            int wordIndex = it->occurrences[0];
            if (rcnt[wordIndex] > 0) {
                rcnt[wordIndex] -= 1;
                if (findMatch(s.substr(i + 1), trie, rcnt)) {
                    return true;
                }
                rcnt[wordIndex] += 1;
            }
        }
        return (accumulate(rcnt.begin(), rcnt.end(), 0) == 0);
    }
    
    int search(vector<int>& nums, int target) {
        size_t prefixlen = numbers::inc_prefix(nums);
        vector<int>::iterator p = lower_bound(nums.begin(), nums.begin() + prefixlen, target);
        if (p != nums.end() && *p == target) {
            cout << "prefix" << prefixlen << endl;
            return p - nums.begin();
        }
        vector <int> suffix(nums.begin() + prefixlen, nums.end());
        p = lower_bound(suffix.begin(), suffix.end(), target);
        if (p != suffix.end() && *p == target) {
            cout << "suffix " << prefixlen << endl;
            return (p - (suffix.begin())) + prefixlen;
        }
        return -1;
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector< pair<int,int> > cnted;
        sort(candidates.begin(), candidates.end());
        for (int c : candidates) {
            cnted.push_back(make_pair(c, target/c));
        }
        
        return numbers::_unique_sum(cnted, 0, target);
    }
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector< pair<int,int> > cnted = numbers::sort_uniq_c(candidates);
        return numbers::_unique_sum(cnted, 0, target);
    }
    
    vector<vector<int>> combinationSum3(int k, int target) {
        vector< pair<int,int> > cnted;
        for (int c=1; c<10; c++) {
            cnted.push_back(make_pair(c, target/c));
        }
        return numbers::_unique_sum_fixed_size(cnted, 0, target, k);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        long mask;
        long upper = 1 << nums.size();
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (mask=0; mask < upper; mask ++) {
            vector<int> can;
            for(int b=0; b<n; b++) if((1<<b) & mask) can.push_back(nums[b]);
            ans.push_back(can);
        }
        return ans;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> cnt(nums.size(), 0);
        for (int v : nums) {
            if (v > 0) {
                if (v <= sz) {
                    cnt[v - 1] += 1;
                }
            }
        }
        for (int i = 0; i<sz; i++) {
            if (cnt[i] == 0) {
                return i + 1;
            }
        }
        return sz + 1;
    }
    
    int trap(vector<int>& height) {
        set<int> hs;
        for (int h : height) {
            hs.insert(h);
        }
        int base = -1;
        int sum = 0;
        for (auto it = hs.begin(); it!= hs.end(); it++) {
            if (base >= 0) {
                sum += numbers::trapping_rain_water(height, base, *it);
            }
            base = *it;
        }
        return sum;
    }
    
    int maxSubArray(vector<int>& nums) {
        vector<int> sums;
        
        int s = 0;
        for(int i=0; i<nums.size(); i++) {
            sums.push_back(s);
            s+=nums[i];
        }
        sums.push_back(s);
        vector<int> maxAfterIndex(nums.size());
        int mval = sums[sums.size() - 1];
        int ans = mval;
        
        for (int i=sums.size() - 2; i>=0; i--) {
            maxAfterIndex[i] = mval;
            if (sums[i] > mval) mval = sums[i];
        }
        for (int i=0; i<maxAfterIndex.size(); i++) {
            int can = maxAfterIndex[i] - sums[i];
            if (can > ans) ans = can;
        }
        return ans;
    }
};

struct Similars { // TCO 2015 Round 1A DIV 1
    int maxsim(int L, int R) {
        return numbers::max_decimal_digits_set_intersection(L,R);
    }
};

int main() {
    Solution s;
    {
        vector<int > D{0};
        int p = s.maxSubArray(D);

        p = s.search(D, 2);
        cout << p << endl;
    }
    {
        string str= "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
         vector<string> words {"ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba"};
         
        vector<int> ans = s.findSubstring(str, words);
        numbers::dump(ans);
    }
    {
        cout << s.convertToTitle(702) << endl;
        return 0;
    }
    {
        ListNode n1(1);
        ListNode n2(2);
        ListNode n3(3);
        ListNode n4(4);
        
        n1.next = & n2;
        n2.next = & n3;
        n3.next = & n4;
        ListNode *head = s.swapPairs(&n1);
        lists::dump(head);
        return 0;
    }
    {
        cout<< s.isValid("()[]{}") << endl;
        return 0;
    }
    {
        ListNode n1(1);
        ListNode n2(2);
        ListNode n3(3);
        ListNode n4(4);
        ListNode n5(5);
        n1.next = & n5;
        n2.next = & n4;
//        n1.next = & n2;
//        s.removeNthFromEnd(& n1, 1);
//        s.mergeTwoLists(&n1, &n2);
        vector<ListNode*> para {&n1, &n3, &n2};
        ListNode *head = s.mergeKLists(para);

        lists::dump(head);
        return 0;
    }
    {
        ReplacingDigit s;
        vector<int > A {100, 90};
        vector<int > D
        {0, 0, 0, 0, 2, 1, 0, 0, 0};
        
        cout<<s.getMaximumStockWorth(A, D)<<endl;
        return 0;
    }
    {
        ExploringNumbers s;
        cout<<s.numberOfSteps(12366)<<endl;
        return 0;
    }
    {
        Similars s;
        cout<<s.maxsim(444, 454)<<endl;
    }
    
    /*
    
    {
        int input[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
        vector<int> height(input, input + (sizeof(input) / sizeof(int)));
    
        s.fourSum(height, -236727523);
    }
     
    {
        int input[] = {-2,0,5,-1,-5,5,3};
        vector<int> height(input, input + (sizeof(input) / sizeof(int)));
        
        vector<vector<int> > res = s.fourSum(height, -2);
        cout<<res.size()<<endl;
    }
     */
}
