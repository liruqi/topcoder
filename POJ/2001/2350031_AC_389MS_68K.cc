#include <stdio.h>
#include <string.h>

int n;
char A[1000][21];
char B[1000][21];

int unique(int s,int p){
    for(int i=0;i<n;i++) if(i!=s)
    {
        if(strncmp(A[i],A[s],p)==0) return 0;
    }
    return 1;
}

int main()
{
    int i=0,j,minlen=0;
    while(gets(A[i])) i++;
    n=i;

    for(i=0; i<n; i++){
        printf("%s ",A[i]);
        for(j=1; A[i][j] != '\0'; j++)
        {
            if(unique(i,j)){
                for(int k=0;k<j;k++)
                    putchar(A[i][k]);
                putchar(10);
                break;
            }
        }
        if(A[i][j]=='\0')
            puts(A[i]);
        
    }
    scanf("%*d");
}

    /*
    for(i=0; A[0][i]!='\0'; i++)
    {
        if(!identical(i))
           break; 
    }
    */
    
    //minlen=i;
