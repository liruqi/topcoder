//
//  main.cpp
//  topcoder
//
//  Created by RUQI LI on 28/9/15.
//  Copyright © 2015 CMCM. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define P_VECTOR(x) { for(int i=0;i<x.size(); i++) std::cout << x[i] << " "; std::cout << endl; }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int main(int argc, const char * argv[]) {
    TreeNode root(1);
    TreeNode left(2);
    root.left = & left;
    Solution s;
    vector<int> ret = s.rightSideView(& root);
    P_VECTOR(ret);
    return 0;
}

