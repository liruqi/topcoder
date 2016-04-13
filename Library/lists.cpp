
#include <string>

using namespace std;

// single list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode ** get(ListNode **it, int k) {
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
};

class Solution {
public:
    //https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        size_t sz = lists::size(head);
        int k = sz - n;
        ListNode **it = lists::get(& head, k);
        lists::remove(it);
        return head;
    }
};
