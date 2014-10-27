#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef max
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#endif

#define sum(a,b) ((a)+(b))

#define MAXSZ 100000
typedef long long LL;
int len, dat[MAXSZ];
struct node {
    LL sum, delta;
    int l, r;
};

struct node tree[MAXSZ * 4];

void build_tree(int p, int l, int r) {
    tree[p].delta = 0;
    tree[p].l = l;
    tree[p].r = r;
    if (l>=r) {
        tree[p].sum = dat[l];
        // cout<<"% "<<l<<" "<<r<<" "<<p<<" -> "<<n[p]<<endl;
        return ;
    }
    int m=(l+r)/2;
    build_tree( 2*p, l, m); 
    build_tree( 2*p+1, m+1, r);
    tree[p].sum = sum(tree[2*p].sum, tree[2*p+1].sum);
}

LL query_tree(int p, int ll, int rr) {
    struct node* np = tree + p;
    int sz = rr - ll + 1; 
    if (np->l==ll && np->r==rr) {
        // cout<<"# "<<ll<<" "<<rr<<" "<<np->delta<<endl;
        return np->sum + sz * np->delta;
    }
    int m=(np->l+np->r)/2;
    if (rr <= m) return query_tree(2*p,  ll, rr) + sz * np->delta;
    if (ll > m) return query_tree(2*p+1,  ll, rr) + sz * np->delta;

    LL ln = query_tree( 2*p,  ll, m);
    LL rn = query_tree( 2*p+1, m+1, rr);
    // cout<<"## "<<ln<<" + "<<rn<<" + "<< sz << "*" << np->delta<<endl;
    return ln + rn + sz * np->delta ; 
}

LL update_tree(int p, int ll, int rr, LL d) {
    struct node* np = tree + p;
    int sz = rr - ll + 1; 
    
    if (np->l==ll && np->r==rr) {
        np->delta += d;
        // cout<<"$ "<<ll<<" "<<rr<<" "<<np->delta<<endl;
        return  np->delta;
    }

    int m=(np->l+np->r)/2;
    
    np->sum += d * sz;
    //cout<<"$$$ "<<ll<<" "<<rr<<" "<<m<<endl;
    if (rr <= m) return update_tree(2*p,  ll, rr, d);
    if (ll > m) return update_tree(2*p+1,  ll, rr, d);

    update_tree( 2*p,  ll, m, d);
    update_tree( 2*p+1, m+1, rr, d);
    // cout<<"$$ "<<ll<<" "<<rr<<" "<<np->delta<<endl;
    return  np->delta ; 
}

int main () {
    int q,l,r;
    LL  delta;
    char cmd[3];
    scanf("%d %d", &len, &q);
    for(int i=0;i<len;i++)
        scanf("%d", dat+i);
    build_tree( 1, 0, len-1);
    for(int i=0;i<q;i++) {
        scanf("%s %d %d",cmd, &l, &r);
        // printf("#%s %d %d\n", cmd,l,r);
        l -= 1; r-=1;
        if (cmd[0]=='Q') { 
            LL res = query_tree( 1,  l, r);  
            printf("%lld\n", res);
        } else {
            scanf("%lld", &delta);
            update_tree(1, l, r, delta);
        }
    }
}

