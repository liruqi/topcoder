//
//  main.cpp
//  topcoder
//
//  Created by RUQI LI on 28/9/15.
//  Copyright © 2015 CMCM. All rights reserved.
//

// leetcode problem does not exist, problem description similiar to https://leetcode.com/problems/bitwise-and-of-numbers-range/
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

class Solution {
public:
    int singleBitwiseAnd(int x, int p) {
        long long len = 1;
        len = (len << p);
        long long mod = (len << 2);
        int rem = x % mod;
        int type = rem / len;
        if (type == 0) return 0;
        if (type == 1) {
            if (len == 1) return 1;
            rem -= len;
            return (1 + rem) % 2;
        }
        if (type == 2) {
            if (len == 1) return 1;
            return 0;
        }
        if (type == 3) {
            if (len == 1) return 0;
            rem = (rem % len);
            return (1 + rem) % 2;
        }
        return 0;
    }
    
    int accBitwiseAnd(int x) {
        if (x < 0) return 0;
        int r=0;
        int bitp = 0;
        for (; bitp<32; bitp++) {
            r ^= (singleBitwiseAnd(x, bitp) << bitp);
        }
        return r;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        return accBitwiseAnd(n) ^ accBitwiseAnd(m-1);
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
