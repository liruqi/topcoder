#include <algorithm>
#include <deque>
using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)


int N, M, K;
int welcome[128][10000 + 2];
int length[128][10000 + 2];
int dp[128][10000 + 2];
int sw[10000 + 2], sl[10000 + 2];

int main ()
{
    while(EOF != scanf("%d %d %d", &N, &M, &K)) {
        if (N<=0) break;
        N++;
        for (int i=1; i<= N; i++) for (int j=1; j<=M; j++) scanf("%d", welcome[i]+j);
        for (int i=1; i<= N; i++) for (int j=1; j<=M; j++) scanf("%d", length[i]+j);
        fill(dp[0], dp[0]+M+1, 0);
        for (int i=1; i<= N; i++) {
            fill(dp[i], dp[i]+M+1, 0);
            sw[0] = 0; sl[0] = 0;
            REP_1(j, M) { sw[j] = sw[j-1] + welcome[i][j]; sl[j] = sl[j-1] + length[i][j]; }
            
            deque<int> Q; Q.push_back(0);
            for (int j=0; j<=M; j++) {
                while(Q.size() && sl[j] - sl[Q.front()] > K) Q.pop_front();
                while(Q.size() && dp[i-1][j] - sw[j] > dp[i-1][Q.back()] - sw[Q.back()]) Q.pop_back();
                Q.push_back(j);
                dp[i][j] = max(dp[i][j], dp[i-1][Q.front()] - sw[Q.front()] + sw[j]);
            }

            sw[M] = 0; sl[M] = 0;
            for (int j=M; j>0; j-=1) {
                sw[j-1] = sw[j] + welcome[i][j]; sl[j-1] = sl[j] + length[i][j];
            }
 
            Q.clear(); Q.push_back(M);
            for (int j=M; j>=0; j-=1) {
                while(Q.size() && sl[j] - sl[Q.front()] > K) Q.pop_front();
                while(Q.size() && dp[i-1][j] - sw[j] > dp[i-1][Q.back()] - sw[Q.back()]) Q.pop_back();
                Q.push_back(j);
                dp[i][j] = max(dp[i][j], dp[i-1][Q.front()] - sw[Q.front()] + sw[j]);
                //printf ("# j: %d - start: %d sl[Q.front]: %d\n", j, Q.front(), sl[Q.front()]);
            }
            /*
            printf ("# row: %d ", i);
            for (int j=0; j<=M; j++) {
                printf ("%d ", dp[i][j]);
            }
            printf ("#\n"); */
        }
        printf ("%d\n", * max_element(dp[N], dp[N]+M+1));
    }
}

