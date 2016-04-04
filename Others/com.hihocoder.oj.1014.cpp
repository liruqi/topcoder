//
//  main.cpp
//  topcoder
//
//  Created by RUQI LI on 28/9/15.
//  Copyright © 2015 MSFT. All rights reserved.
//


// http://hihocoder.com/problemset/problem/1014
#include <iostream>
#include <vector>
#include "assert.h"
#include "string.h"

using namespace std;


#define csize 26
#define maxn 100000
typedef struct _node{
    struct _node *next[csize];
    int cnt;
} node;

node nday[maxn*csize];

char word[csize];
int nodeNumber, top;

void addNode(node &cnd, int idx) {
    int pos=word[idx]-'a';
    cnd.cnt ++;
    if(word[idx] == 0) {
        return;
    }
    assert(pos < csize);
    assert(pos >= 0);

    if(cnd.next[pos]==NULL) {//allocate new space
        memset(nday+top,0,sizeof(nday[top]));
        cnd.next[pos] = nday+top;
        top++;
    }
    addNode(*cnd.next[pos], idx+1);
}

int queryNode(node *root) {
    node *cnd = root;
    char *chr = word;

    for (; (*chr); chr ++) {
        if (cnd == NULL) {
            return 0;
        }
        int pos= *chr - 'a';
        assert(pos < csize);
        assert(pos >= 0);
        cnd = cnd->next[pos];
    }
    if (cnd == NULL) {
        return 0;
    }
    return cnd->cnt;
}

int main() {
    top = 0;
    node trie;
    memset(&trie,0,sizeof(trie));
    cin >> nodeNumber;
    for (int i=0; i<nodeNumber; i++) {
        scanf("%s",word); //"abc", "abc\0"
        addNode(trie, 0);
    }
    
    int qNumber = 0;
    cin >> qNumber;
    for (int i=0; i<qNumber; i++) {
        scanf("%s",word); //"abc", "abc\0"
        printf("%d\n", queryNode(&trie));
    }
}