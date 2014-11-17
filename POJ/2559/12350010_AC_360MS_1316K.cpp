#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

typedef struct snode {
    long long val;
    int start_idx;
} node;

int main () 
{
  int i, N, k;
  while(1) {

    scanf("%d", & N);
    if (N == 0) break;
    //printf ("# %d\n", N);
    long long ret = 0;
    
    stack<node> q;

    for (i=0; i<=N; i++) {
      if (i==N) {
        k = 0;
      } else {
        scanf("%d", &k);
      }
      node current;
      current.val = k;
      current.start_idx = i;

      while (q.size() && k <= q.top().val) {
        current.start_idx = q.top().start_idx;
        // printf ("# %d * (%d - %d)\n", q.top().val, i, q.top().start_idx);
        ret = max(ret, q.top().val * (i-q.top().start_idx));
        q.pop();
      }
      q.push(current);
    }
    
    printf ("%lld\n", ret);
  }
}
