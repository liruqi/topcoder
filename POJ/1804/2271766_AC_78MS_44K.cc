#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn=500000;
int A[maxn];
int main()
{
    long long cnt;
    int n, i, j, c=0, tc;
    scanf("%d", &tc);
    while(scanf("%d", &n)!=EOF && c++ < tc)
    {
        cnt=0;
        for(i=0; i<n; i++) scanf("%u", A+i);
        for(i=0; i<n; i++)
        {
            int midx=i;
            
            for(j=i+1; j<n; j++)
                if(A[j]<A[midx])
                    midx=j;
            j=midx;
            while(j>i){
                A[j]=A[j-1];
                j--;
            }
            cnt += midx-i;
        }
        printf("Scenario #%d:\n%d\n\n", c, cnt);
    }
    return 0;
}
