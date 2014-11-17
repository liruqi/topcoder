#include <stdio.h>

int A[20],i,j,tmp;
int main()
{
    A[1]=1;
    A[2]=3;
    for(i=3; i<13; i++)
    {
        A[i]=2*A[i-2]+3;
        for(j=3; j<i ;j++){
            tmp = (1<<j)-1+2*A[i-j];
            if(tmp<A[i])
                A[i]=tmp;
            else 
                break;
        }
    }
    for(i=1; i<13; i++)
    {
        printf("%d\n", A[i]);
    }
    getchar();
    return 0;
}
