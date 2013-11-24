#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* Copyright 2005-2011 Mark Dufour and contributors; License Expat (See LICENSE) */

int input_int() {int x; scanf("%d", &x); return x;}
int input_str(char* x) {scanf("%s", x); return 0;}
#define __mods(x,y) ((x)%(y))
/* iteration macros */

#define INC_FOR(i, l, u, s) \
    for(i=l; i<u; i+=s) {

#define END_FOR }
char board[100][100];
int dp[2][1<<15];

void solve() {
    int M, N, blockMask, cmask, cur, finalMask, mask, n, pm, pre, qcnt, queenMask, res, valid;

    N = input_int();
    M = input_int();
    for (int r=0; r<N; r++)
        input_str(board[r]);

    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    res = -1;

    for (int r=0; r<N; r+=1) {
        pre = __mods((r+1), 2);
        cur = __mods(r, 2);

        memset(dp[cur], 0, sizeof(int) * (1<<(3*M)));

        res = -1;

        INC_FOR(mask,0,(1<<(3*M)),1)
            if (dp[pre][mask]==0) {
                continue;
            }
            cmask = 0;
            blockMask = 0;
            int c;
            INC_FOR(c,0,M,1)
                if (board[r][c]!='.') {
                    blockMask = ((blockMask)|((1<<c)));
                }
                pm = __mods((mask>>(3*c)), 8);
                if ((((pm)&(1))>0)) {
                    if ((c>0) && (board[r][c-1] == '.')) {
                        cmask = ((cmask)|((1<<(3*(c-1)))));
                    }
                }
                if (((pm)&((1<<1)))>0) {
                    if (board[r][c] == '.') {
                        cmask = ((cmask)|((1<<((3*c)+1))));
                    }
                }
                if (((pm)&((1<<2)))>0) {
                    if (((c+1)<M) and board[r][c+1] == '.') {
                        cmask = ((cmask)|((1<<((3*(c+1))+2))));
                    }
                }
            END_FOR


            INC_FOR(queenMask,0,(1<<M),1)
                if ((((queenMask)&(blockMask))>0)) {
                    continue;
                }
                qcnt = 0;
                valid = 1;

                INC_FOR(c,0,M,1)
                    if (((queenMask)&((1<<c)))) {
                        qcnt = (qcnt+1);
                        if ((qcnt>1)) {
                            valid = 0;
                            break;
                        }
                    }
                    else if (((blockMask)&((1<<c)))) {
                        qcnt = 0;
                    }
                END_FOR

                if (valid) {
                finalMask = 0;

                INC_FOR(c,0,M,1)
                    if (((queenMask)&((1<<c)))) {
                        finalMask = ((finalMask)|((7<<(3*c))));
                    }
                END_FOR

                if (((finalMask+cmask)==((finalMask)|(cmask)))) {
                    finalMask = ((finalMask)|(cmask));
                    dp[cur][finalMask] += dp[pre][mask];
                    dp[cur][finalMask] %= 1000000007;
                    //printf("# %d finalMask:%o mask:%o cmask:%o %d\n", r, finalMask, mask, cmask, dp[pre][mask]);
                    res += dp[pre][mask];
                    res %= 1000000007;
                }
                }
            END_FOR

        END_FOR

    END_FOR

    //printf("# %d %d %d\n", res, N, M);
    printf("%d\n", res  );
}

void __init() {
    int  __ss_case, k;
    __ss_case = input_int();

    for (int k=0; k<__ss_case; k+=1)
        solve();
}


int main(int, char **) {
    __init();
}
