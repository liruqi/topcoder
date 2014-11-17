#include <stdio.h>

int tc, n,i,j;
long long A[45];
int main()
{
    
    scanf("%d",&tc);
    A[1]=2;
    A[2]=3;
    for(i=3; i<45; i++)
    A[i]=A[i-1]+A[i-2];
    
    for(i=1;i<=tc;i++)
    {
        scanf("%d",&n);
        printf("Scenario #%d:\n%d\n\n", i, A[n]);
    }
    return 0;
}
