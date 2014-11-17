
#include <stdio.h>

double A[4][5];
double B[4][4];
double A1, A2, A3, AA;
double det(int c){
    int i, j;
    for(i=1; i<4; i++)
        for(j=1; j<4; j++)
        B[i][j]=A[i][j];
    if(c<4)
    for(i=1; i<4; i++)
        B[i][c]=A[i][4];
    return B[1][1]*(B[2][2]*B[3][3]-B[2][3]*B[3][2])-
           B[1][2]*(B[2][1]*B[3][3]-B[2][3]*B[3][1])+
           B[1][3]*(B[2][1]*B[3][2]-B[2][2]*B[3][1]);
}
int main()
{
    int tc, i ,j;
    scanf("%d",&tc);
    while(tc--) {
        for(i=1; i<4; i++)
        for(j=1; j<5; j++)
        scanf("%lf",A[i]+j);
        A1=det(1);
        A2=det(2);
        A3=det(3);
        AA=det(4);
        printf("%.0lf %.0lf %.0lf %.0lf\n", A1,A2,A3,AA);
        if(AA)
            printf("Unique solution: %.3lf %.3lf %.3lf\n\n", 
                    A1/AA,A2/AA,A3/AA);
        else 
            printf("No unique solution\n\n");
    }
}
