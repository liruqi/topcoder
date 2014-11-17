#include <stdio.h>
#include <string.h>
char A[10][10];
const char eoi[]="ENDOFINPUT";
int R,C;
int main()
{
int i, j;
scanf("%s", A[0]);
while(strcmp(A[0], eoi)){
scanf("%d%d", &R,&C);
for(i=0; i<R; i++) 
scanf("%s", A[i]);
for(i=0; i<R-1; i++){
for(j=0; j<C-1; j++)
{
char c=(A[i+1][j]+A[i+1][j+1]+A[i][j]+A[i][j+1])/4;
putchar(c);
}
putchar('\n');
}
scanf("%*s%s", A[0]);
}
return 0;
}
