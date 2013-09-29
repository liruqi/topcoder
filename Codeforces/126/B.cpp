// For http://codeforces.com/contest/126/problem/B
// by liruqi@gmail.com

#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int input_int() { int x; scanf("%d", &x); return x; }

#define ZAXLEN 1200000
int F[ZAXLEN];
char textbuf[ZAXLEN];
char pattern[ZAXLEN];
int  prefix[ZAXLEN];

int build_failure_function(int plen, int *Z)
{
    int i,j;

    memset(F, 0, sizeof(int) * plen);
    memset(Z, -1, sizeof(int) * plen);
    F[0] = F[1] = 0; // always true
    Z[0] = plen;
    int pmmax = 0;
    for(i = 2; i <= plen; i++) {
        j = F[i - 1]; 
        while(1) {
            if(pattern[j] == pattern[i - 1]) { 
                F[i] = j + 1; Z[i - F[i]] = F[i]; break; 
            }
            // if we cannot "expand" even the empty string
            if(j == 0) {F[i] = 0; Z[i - 1]=0; break; }
            // else go to the next best "candidate" partial match
            j = F[j]; Z[i - j - 1] = max(j,Z[i - j - 1]) ;
        }
        if (i < plen) pmmax = max(pmmax, F[i]); 
    }

    int pm = F[plen];
    while (pm > 0) {
        if (pmmax >= pm) {
            //printf("# %d %d",pmmax, pm);
            puts(pattern + plen - pm);
            return pmmax;
        }
        else {
            pm = F[pm];
        }
    }
    
    puts("Just a legend");
    return 0;
}


int main(int argc, char * argv[]) {
    int plen;
        memset(prefix, 0, sizeof(prefix));
        scanf("%s", pattern);
        plen = strlen(pattern);
        
        build_failure_function(plen, prefix);
}
