#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define BACK_TO_ROOT 10
#define MOD 1000000007

struct trieNode {
    int next[11];
    int id;
    
    void init(int _id) { id=_id; fill(next,next+11,-1); } 
};

trieNode trie[100 * 100];
int trieTop;

trieNode * trieCreate() {
    trieNode* root = trie + trieTop;
    root->init(trieTop);
    trieTop ++;
    return root;
}

int updateTrie(trieNode *node, int *cur, int *pre) {
    // cout<<"#Node "<<node->id<<" "<<pre[node->id]<<"\n";
    for (int i=0;i<BACK_TO_ROOT;i++) {
        if (node->next[i] >= 0) {
            trieNode *link = trie + node->next[i];
            cur[link->id] = (cur[link->id] + pre[node->id]) % MOD;
            if (link != trie) {
                updateTrie(link, cur, pre);
            }
        }
    }
    if (node->next[BACK_TO_ROOT] >= 0) {
        cur[0] += cur[node->id];
        cur[0] %= MOD;
    }
    return 0;
}

int dp[2][100 * 100];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,M; cin>>N>>M;
    
    trieTop = 0;
    trieNode* root = trieCreate();
    
    for (int i=0;i<N;i++) {
        string s; cin>>s;
        // add s to trie
        trieNode* cur = root;
        for (int j=0;j<s.size();j++) {
            int c = s[j] - 'a';
            trieNode* next;
            if (cur->next[c] < 0)  // not set
            {
                next = trieCreate();
            } else {
                next = trie + cur->next[c];
            }
            cur->next[c] = next->id;
            cur = next;
        }
        cur->next[BACK_TO_ROOT] = root->id;
    }
    
    fill(dp[1], dp[1]+trieTop, 0);
    int ans=1;
    dp[1][root->id] = 1;
    
    for (int s=0;s<M;s++) {
        int *cur = dp[s%2];
        int *pre = dp[1- s%2];
        fill(cur, cur+trieTop, 0);
        updateTrie(root, cur, pre);
        /* cout<<"#"<<s<<": ";
        for (int i=0; i<trieTop; i++) cout<<cur[i]<<" ";
        cout<<endl;
        */
        ans = (ans + cur[0]) % MOD;
    }
    cout<<ans<<endl;
    return 0;
}

