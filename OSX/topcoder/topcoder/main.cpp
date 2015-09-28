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
#define P_BASIC(x) { std::cout << x << endl; }

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

// https://leetcode.com/problems/bitwise-and-of-numbers-range/
class Solution {
public:
    int singleBitwiseAnd(int m, int n, int p) {
        long long len = 1;
        len = (len << p);
        long long mod = (len << 2);
        if ((m / mod) != (n / mod)) {
            return 0;
        }
        
        int rem = m % mod;
        int ren = n % mod;
        int type = rem / len;
        if (type != (ren / len)) {
            return 0;
        }
        
        if (type == 0) return 0;
        if (type == 1) {
            return 1;
        }
        if (type == 2) {
            return 0;
        }
        if (type == 3) {
            return 1;
        }
        return 0;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        int r=0;
        int bitp = 0;
        for (; bitp<32; bitp++) {
            r ^= (singleBitwiseAnd(m, n, bitp) << bitp);
        }
        return r;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    ;
    P_BASIC(s.rangeBitwiseAnd(0, 1));
}

/*
int main(int argc, const char * argv[]) {
    TreeNode root(1);
    TreeNode left(2);
    root.left = & left;
    Solution s;
    vector<int> ret = s.rightSideView(& root);
    P_VECTOR(ret);
    return 0;
}
*/
