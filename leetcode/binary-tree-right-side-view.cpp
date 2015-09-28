/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> bfs;
        vector<int> rsv;
        if (root) {
        int depth = 1;
        bfs.push_back(root);
        
        for (; bfs.size(); depth++) {
            rsv.push_back(bfs[0]->val);
            vector<TreeNode*> nxt;
            for (vector<TreeNode*>::iterator it=bfs.begin(); it!=bfs.end(); it++) {
                if ((*it)->right) {
                    nxt.push_back((*it)->right);
                }
                if ((*it)->left) {
                    nxt.push_back((*it)->left);
                }
            }
            if (nxt.size() == 0) break;
            bfs.clear();
            bfs.assign(nxt.begin(), nxt.end());
        }
        }
        return rsv;
    }
};
