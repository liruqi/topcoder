// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/


#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
} ListNode;


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* ret = NULL;
        ListNode* prev = NULL;
        int carry = 0;
        while (l1 || l2 || carry) {
            int d = carry;
            if (l1) {d += l1->val; l1=l1->next;}
            if (l2) {d += l2->val; l2=l2->next;}
            carry = d / 10;
            d = d % 10;
            ListNode* p = new ListNode(d);
            if (! ret) {
                ret = p;
                prev = p;
            } else {
                prev->next = p;
                prev = p;
            }
            
        }
        return ret;
    }
};

int main () {
    Solution s ;
    
}
