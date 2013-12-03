#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

typedef struct snode {
    int val;
    int start_idx;
} node;
int grid[2000][2000 + 1];

int main () 
{
  int i, N, M, j;
  while(EOF != scanf("%d %d", &M, &N)) {
    int ret = 0;
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            scanf("%d", grid[i]+j);
            if (grid[i][j] > 0 && i > 0 && grid[i-1][j] > 0) grid[i][j] = grid[i-1][j]+1; 
        }
    }


    for (i=0; i<M; i++) {
      int* h = grid[i];
      h[N] = 0;
      stack<node> q;
      for (j=0; j<=N; j++) {
        int k = h[j];
        node current;
        current.val = k;
        current.start_idx = j;

        while (q.size() && k <= q.top().val) {
            current.start_idx = q.top().start_idx;
            ret = max(ret, q.top().val * (j-q.top().start_idx));
            q.pop();
        }
        q.push(current);
      }
    }
    
    printf ("%d\n", ret);
  }
}
