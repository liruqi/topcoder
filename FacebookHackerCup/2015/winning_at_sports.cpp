//
//  main.cpp
//  HackerCup
//
//  Created by liruqi on 1/18/15.
//  Copyright (c) 2015 liruqi. All rights reserved.
//
// Corporate Gifting

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include "string.h"
#include "stdio.h"
#include <sys/resource.h>

#pragma comment(linker, "/STACK:36777216")

using namespace std;
#define MAXSZ 200000


vector<int> tree[MAXSZ];
pair<size_t, int> dp[MAXSZ][2]; // first: node value, second: sum

int n;

bool lessfunc (pair<size_t,int> i,pair<size_t, int> j) { return (i.second<j.second); }

void search(int node) {
    vector< pair<size_t, int>  > r;
    
    size_t maxval = 2;
    for (int i=0; i<tree[node].size(); i++) {
        int sub = tree[node][i];

        search(tree[node][i]);
        maxval = max(maxval, dp[sub][0].first + 1);
        maxval = max(maxval, dp[sub][1].first + 1);

    }
    
    for (int v=1; v<=maxval; v++) {
        int minsum = v;
        for (int i=0; i<tree[node].size(); i++) {
            int sub = tree[node][i];
            
            int minval = INT32_MAX;
            for (int j=0; j<2; j++) {
                pair<int, int> p = dp[sub][j];
                if (p.first != v) {
                    minval = min(minval, p.second);
                }
            }
            
            if (minval == INT32_MAX) {
                cout  << "WTF" << endl;
            }
            minsum += minval;
        }
        r.push_back( make_pair(v, minsum));
    }
    sort(r.begin(), r.end(), lessfunc);
    dp[node][0] = r[0];
    dp[node][1] = r[1];

}

int main () {
    
    int kase;
    freopen ("/Users/liruqi/Documents/iOS/HackerCup/HackerCup/corporate_gifting.txt","r",stdin);
    
    
    scanf("%d", &kase);
    for (int k=1; k<=kase; k++) {
        int leader;
        scanf("%d", &n);
        for (int i=0; i<n; i++) tree[i].clear();

        for (int i=0; i<n; i++) {
            scanf("%d", &leader);
            if (leader > 0)
                tree[leader - 1].push_back(i);
        }
        search(0);
        cout<<"Case #"<<k<<": "<< dp[0][0].second<<endl;
    }
}
