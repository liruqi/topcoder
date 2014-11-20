/**
 * https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
 * 居然写了两个小时......
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode n1 = ListNode(1);    
ListNode n2 = ListNode(2);
ListNode n3 = ListNode(3);
ListNode n4 = ListNode(4);


class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) return head;
        ListNode **p = & head;
        ListNode * ret = head;
        while(p && *p) {
            ListNode *end = *p;
            //cout<< "# p: " << end ->val    << endl;
            for(int i=0; i<k; i++) {
                if (! end) return ret;
                end = end->next;
            }
            //if (end)
            //cout<< "# e: " <<  end->val   << endl;
            //else 
            //cout<< "# e: NULL "  << endl;
            
            ListNode *last = *p;
            ListNode *it = (*p)->next;
            (*p)->next = end;
            
            while (it != end) {
                ListNode *next = it->next;   
                it->next = last;
                last = it;
                it = next;
            }
            if (*p == head) {
                ret = last;
                p = & (head->next);
            }
            else {
                it = *p;
                *p = last;
                p = &(it->next);
            }
            
        }
        return ret;
    }
};

int main (int argc, char* argv[]) {
    Solution s ;
    
    n1 . next = & n2;
    n2 . next = & n3;
    n3 . next = & n4;
    ListNode* p = s.reverseKGroup(& n1, 2);
    cout << p  << endl;
    cout << p ->val  << endl;
    cout << p->next ->val  << endl;
    cout << p->next->next->val   << endl;
    if (p->next->next->next)
    cout << p->next->next->next ->val  << endl;
}
