#include <stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

#define MAXSZ 51200
int len, dat[MAXSZ];
struct node {
    int ceil, floor;
};

struct node tree[MAXSZ * 2];

void build_tree(int p, int l, int r) {
    if (l>=r) {
        tree[p].ceil = dat[l];
        tree[p].floor = dat[l];
        // cout<<"% "<<l<<" "<<r<<" "<<p<<" -> "<<n[p]<<endl;
        return ;
    }
    int m=(l+r)/2;
    build_tree( 2*p, l, m); 
    build_tree( 2*p+1, m+1, r);
    tree[p].ceil = max(tree[2*p].ceil, tree[2*p+1].ceil);
    tree[p].floor = min(tree[2*p].floor, tree[2*p+1].floor);
}

struct node query_tree(int p, int l, int r, int ll, int rr) {
    if (l==ll && r==rr) {
        // cout<<"$ "<<l<<" "<<r<<" "<<ll<<endl;
        return tree[p];
    }
    int m=(l+r)/2;
    if (rr <= m) return query_tree(2*p, l, m, ll, rr);
    if (ll > m) return query_tree(2*p+1, m+1, r, ll, rr);

    
    struct node ln = query_tree( 2*p, l, m, ll, m);
    struct node rn = query_tree( 2*p+1, m+1, r, m+1, rr);
    ln.ceil = max(ln.ceil, rn.ceil); 
    ln.floor = min(ln.floor, rn.floor);
    return ln; 
}

int main () {
    int q,l,r;
    scanf("%d %d", &len, &q);
    for(int i=0;i<len;i++)
        scanf("%d", dat+i);
    build_tree( 1, 0, len-1);
    build_tree( 1, 0, len-1);
    for(int i=0;i<q;i++) {
        scanf("%d %d", &l, &r);
        l -= 1; r-=1;
        struct node res = query_tree( 1, 0, len-1, l, r);  
        // cout<<"# "<< upper << " "<<lower<<endl;
        printf("%d\n", res.ceil - res.floor);
    }
}

