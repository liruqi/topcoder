#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ll long long
#define maxl 40000
#define INF 0x3f3f3f3f

using namespace std;

//vector<int> deadcnt[maxl];
set<int> dead[maxl];
set<int>::iterator setit, setjt;
int bithead[maxl * 4];
int bittail[maxl * 4];


int result,xx,yy, W, H, P, Q, N, X, Y, a, b, c, d;

void updatebit(int * tree, int idx) {
    idx += 1;
    while (idx <= W) {
        tree[idx] += 1;
        idx += (idx & -idx);
    }
}

int readbit(int * tree, int idx) {
    idx += 1;
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    //if (tree == bithead) printf ("#read: [%d,%d] %d\n", idx-1, yy, sum);
    return sum;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int q=1; q<=tc; ++q) {
		scanf("%d %d %d %d %d %d %d %d %d %d %d", &W, &H, &P, &Q, &N, &X, &Y, &a, &b, &c, &d);
		//printf("#%d %d %d %d %d %d %d %d %d %d %d\n", W, H, P, Q, N, X, Y, a, b, c, d);
        memset(bithead, 0, sizeof(bithead));
        memset(bittail, 0, sizeof(bittail));

        int it=0, xxx,yyy;
        for (it=0;it<H;it++) {
            //deadcnt[yy] = vector<int>();
            dead[it] = set<int>();
        }
        it = 0;
        xx=X;
        yy=Y;
        while (it < N) {
            // printf("#x: %d y: %d \n", xx, yy);
            dead[yy].insert(xx);
            xxx =  (xx * a + yy * b + 1) % W;
            yyy =  (xx * c + yy * d + 1) % H;
            xx = xxx; yy = yyy;
            it ++;
        }
        
        int lastlinesum = 0;
        for (yy=0; yy<Q; yy++)  {
            if (dead[yy].size() > 0) {
            for (setit=dead[yy].begin(); setit!=dead[yy].end(); setit++) {
                //printf ("#Add [%d, %d]\n",yy, *setit);
                updatebit(bithead, *setit);
            }
            }

            if (yy == Q-1) {
                //count Q-1 line
                result = 0;
                for (xx=P-1; xx<W; xx++) {
                    if ( readbit(bithead, xx) - readbit(bithead, xx-P) == 0) {
                        result += 1;
                        lastlinesum += 1;
                    }
                }
            }
        }

        //printf ("#Y = 1: result = %d\n",result);
        for (yy=Q; yy<H; yy++) {
            if (dead[yy-Q].size() + dead[yy].size() == 0) {
                result += lastlinesum;
                continue;
            }
            for (setit=dead[yy-Q].begin(); setit != dead[yy-Q].end(); setit++) {
                updatebit(bittail, *setit);
            }
            for (setit=dead[yy].begin(); setit != dead[yy].end(); setit++) {
                updatebit(bithead, *setit);
                //printf ("#Add [%d, %d]\n",yy, *setit);
            }

            lastlinesum = 0;
            for (xx=P-1; xx<W; xx++) {
                if ( readbit(bithead, xx) + readbit(bittail, xx-P) == readbit(bithead,xx-P) + readbit(bittail,xx)) {
                    result += 1;
                    lastlinesum +=1;
                }
            }
        }
		printf("Case #%d: %d\n", q, result);
	}
	return 0;
}

