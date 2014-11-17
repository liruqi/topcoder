#include<stdio.h>
#include<string.h>

#define MAXN 3100
#define MAXS 512

int SG[MAXN];
char NG[MAXS];
int Sprague_Grundy(int x){
    int i, j, k;
    memset(NG,0,sizeof(NG));
    for(i=3;i<6;i++) 
    	NG[SG[x-i]]=1;
    for(i=1;i<(x-5);i++){
        j=x-5-i; 
     	k=SG[i]^SG[j];
        NG[k] = 1;
    }
    for(i=0;i<MAXS;i++)
        if(!NG[i])
            return i;
}

int main(){
    int i;
    for(i=1;i<4;i++) SG[i]=1;
    SG[4]=2; 
    SG[5]=2;
    for(i=7;i<MAXN;i++) SG[i]=Sprague_Grundy(i);
    scanf("%d",&i);
    puts(SG[i]?"1":"2");
    return 0;
}

