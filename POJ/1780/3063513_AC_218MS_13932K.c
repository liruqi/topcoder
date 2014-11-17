#include<stdio.h>
#define mx 1000000
char path[mx];
int tpt[10];
int xxx[mx];
int yyy[mx];
int ltd[mx];
int top;
int dep;
char vst[mx];
int n;
void dfs_non_rec(){
    int y;
    vst[0]=1;
    do{
        if(dep+1==tpt[n]) return;
        for(y=yyy[dep]+ltd[dep];ltd[dep]<10;++ltd[dep],++y)
            if(!vst[y])
                break;
        if(ltd[dep]==10){
            vst[xxx[dep]]=0;
            dep--;
            ltd[dep]++;
        }
        else {
            path[dep]=ltd[dep];
            dep++;
            xxx[dep]=y;
            yyy[dep]=(y%tpt[n-1]*10);
            ltd[dep]=0;
            vst[y]=1;
        }
    }while(1);
}
void out(){
    int i;
    for(i=n;i;i--)putchar('0');
    for(i=0;i<tpt[n]-1;i++)
        printf("%c",path[i]+'0');
    puts("");
}
int main(){
    int i;
    for(i=1,tpt[0]=1;i<9;i++)
        tpt[i]=tpt[i-1]*10;
    while(-1!=scanf("%d",&n) && n){
        top=dep=0;memset(vst,0,sizeof(vst));
        dfs_non_rec(0);
        out();
    }
}
