#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define maxn 30
char expr[200], buf[500];

int exv[maxn], extop;
void
push(char s, char v){
    exv[extop++] = (s=='+'?1:-1)*(v-'`');
}

int val[maxn];

void 
add(int s, char v){
    int idx=v-'a';
    val[idx]=idx+1+s;
    //printf("%d %c\n",s,v);
}

void
Parse()
{
    int explen,i,j;
    for(i=1,j=0; buf[j]!='\0'; j++){
        if(buf[j]!=' ')
            expr[i++]=buf[j];
    }
    expr[i]='\0';
    explen =i;
    for(i=0;i<explen;){
        int sp=i;
        i++;
        if(isalpha(expr[i])){
            int vp=i;
            int id=0;   //inc / dic
            if(i+2<explen && !isalpha(expr[i+2])){
                i+=2;
                id = (expr[i]=='+'?1:-1);
            }
            push(expr[sp], expr[vp]);
            add(id, expr[vp]);
        }
        else {
            int id=expr[i]=='+'?1:-1;
            i+=2;
            int vp=i;
            push(expr[sp], expr[vp]+id);
            add(id, expr[vp]);
        }
        i++;
    }
}

void
Solve(){
    int s=0, i=0;
    printf("Expression: %s\n",buf);
    for(;i<extop;i++) s+=exv[i];
    printf("value = %d\n", s);
    for(i=0;i<26;i++) if(val[i]!=-1){
        printf("%c = %d\n",'a'+i, val[i]);
    }
}

int
main(){
    int T;
    scanf("%d",&T);
    gets(buf);
    expr[0]='+';
    while(T--){
        memset(val, 0xff, 4*maxn);
        extop=0;
        gets(buf);
        Parse();
        Solve();
    }
    return 0;
}
