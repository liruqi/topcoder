#include <math.h>
#include <stdio.h>

#ifndef abs
#define abs(x) ((x)>0 ? (x):(-(x)))
#endif

int main() {
    while (1) {
        int i, n, best = 0;
        double p[32], total, max = 0, min = 10;
        total = 0;
        scanf("%d", &n);
        if (n<1) break;
        for (i=0;i<n;i++) {
            scanf("%lf", p+i);
            total += p[i];
            if (p[i] > max) max = p[i];
            if (p[i] < min) min = p[i];
        }
        total = total - max - min;

        // printf ("%lf\n", total/(n-2));
        for (i=1; i<n; i++) {
            if (abs(p[i] - total/(n-2)) < abs(p[best] - total / (n-2))) best = i;
        }
        printf ("%d\n", best+1);
    }
}
