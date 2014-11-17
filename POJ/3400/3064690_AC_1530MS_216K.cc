//3400
#include<stdio.h>
#include<algorithm>
int N,D,res;
int idx[10];
struct node{
    int w,v;
}S[10];
void solve(){
    int i,b=0;
    node sa={0,0};
    node sb={0,0};
    for(i=0;i<N;i++){
        node &cur=S[idx[i]];
        if(b){//bunker = 1
            sb.w+=cur.w;
            sb.v+=cur.v;
            if(sb.w-sa.w>D)b=0;
        }
        else{//bunker = 0
            sa.w+=cur.w;
            sa.v+=cur.v;
            if(sa.w-sb.w>D)b=1;
        }
    }
    res>?=sb.v;
}

int main(){
    scanf("%d%d",&N,&D);
    int i;
    for(i=0;i<N;i++)
        scanf("%d%d",&S[i].w,&S[i].v), idx[i]=i;
    do{
        solve();
    }while(std::next_permutation(idx,idx+N));
    printf("%d\n",res);
}
