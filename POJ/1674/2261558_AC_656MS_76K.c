#include <stdio.h>

int A[10000];
unsigned int n, cnt;

void prt(){
    unsigned int i;
    for(i=0; i<n; i++)
    printf("%d ",A[i]);
    puts("");
}
void ins_sort(){
    unsigned int i, j, m;
    for(i=0; i<n; i++){
        m=i;
        for(j=i+1; j<n; j++)
            if(A[j]<A[m])
                m=j;
        if(m!=i){
            //printf("swap %d %d\n", A[i],A[m]);
            cnt++;
            A[i]^=A[m];
            A[m]^=A[i];
            A[i]^=A[m];
        //    prt();
        }
    }
}
int main()
{
    unsigned int i, tc;
    scanf("%d", &tc);
    while(tc--){
        cnt=0;
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", A+i);
        ins_sort();
        printf("%d\n", cnt);
    }
}
