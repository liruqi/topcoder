#include <math.h>
#include <stdio.h>
#include <set>
#include <list>
#include <map>
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;

int seq[120000];
int dp[120000];
map<int,int> loopback[120000]; // score to min value

int main() {
    int n,d;
    while (EOF != scanf("%d%d",&n,&d)) {
        int i, min = 0;
        d+=1;

        for (i=1;i<=n;i++) {
            scanf("%d", seq+i);
        }

        for (i=1;i<=n;i++) {
            map<int, int> minval;
            loopback[i].clear();
            if (i < d) {
                dp[i] = 1;
                minval = loopback[i-1];
                map<int,int>::iterator it = minval.find(dp[i]);
                if (it != minval.end()) {
                    if (it->second > seq[i]) it->second = seq[i];
                } else {
                    minval[dp[i]] = seq[i];
                }
                loopback[i] = minval;
            } else {
                dp[i] = 1;
                minval = loopback[i-d];
                for(map<int,int>::iterator it = minval.begin(); it!=minval.end(); it++) {
                    if (it->second < seq[i]) dp[i] = min(it->first+1, dp[i]);
                }

                map<int,int>::iterator it = minval.find(dp[i]);
                if (it != minval.end()) {
                    if (it->second > seq[i]) it->second = seq[i];
                } else {
                    minval[dp[i]] = seq[i];
                }

                for(map<int,int>::iterator it = minval.begin(); it!=minval.end(); it++) {
                    if (loopback[i-1].find(it->first) != loopback[i-1].end()) {
                        it->second = min(loopback[i-1][it->first], it->second);
                    }
                }
                loopback[i] = minval;
            }

            for(map<int,int>::iterator it = minval.begin(); it!=minval.end(); it++) {
                printf ("# %d %d %d\n", i, it->first, it->second);
            }
        }

        printf ("%d\n", loopback[n].size());
    }
}
