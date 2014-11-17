#include <stdio.h>
#include <string.h>

#define MAXD 0xfffffff
char istr[20], ostr[20];
int ibase, obase;

int display(){
    int i,j,k,len=strlen(istr);
    int maxd=1,bst=0;
    for(i=0;i<7;i++)
        maxd*=obase;
    for(i=len-1, j=1; i>=0; i--, j*=ibase){
        k=isdigit(istr[i])?istr[i]-'0':istr[i]-'A'+10;
        bst+=j*k;
        if(bst>=maxd || bst<0) return 0;//overflow
    }
    memset(ostr,' ',10);
    for(i=6;bst>0 && i>=0;i--){
        j = bst%obase;
        bst /= obase;
        ostr[i] = j<10?('0'+j):('A'+j-10);
    }
    ostr[7]='\n';
    for(i=0;i<=7;i++)putchar(ostr[i]);
    return 1;
}

int main(){
    while(EOF!=scanf("%s%d%d",istr,&ibase,&obase)){
        if(!display())
            puts("  ERROR");
    }
}
