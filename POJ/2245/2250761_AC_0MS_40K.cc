#include <stdio.h>
#include <algorithm>
using std::swap;

int A[50], D[50];
unsigned int n;


int next_arrage(){
    unsigned int i,j;
    for(i=n; A[i]; i--);
    if(n-i==6) 
        return 0;
    while(!A[i])
        i--;
    swap(A[i], A[i+1]);
    i++;
    i++;
    j=n;
    while(A[j] && i<j){
        swap(A[i],A[j]);
        j--;
        i++;
    }
    return 1;
}

int main()
{
    scanf("%u",&n);
    unsigned int i;
    while(n){
        for(i=1; i<=n; i++)
        {
            A[i]=i<7 ? 1 : 0;
            scanf("%d",D+i);
        }
        do{
            for(i=1; i<=n; i++) 
            if(A[i])
                printf("%d ",D[i]);
                putchar(10);
        }while(next_arrage());
        
        putchar(10);
        scanf("%d",&n);
    }
}
