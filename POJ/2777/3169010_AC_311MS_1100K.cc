#include<stdio.h>
#include<algorithm>
using namespace std;
int board[600000];
bool uniform[600000];
int C;
void color(int A,int B,int L,int R,int P){
    if(A>=B || L>=R) return;
    else if(A==L && B==R) board[P]=(1<<C),uniform[P]=true;
    else {
        int M=(L+R+1)/2;
        if(uniform[P]){
    		board[2*P] = board[P];
    		board[2*P+1] = board[P];
    		uniform[2*P] = true;
    		uniform[2*P+1] = true;
    		uniform[P]=false;
    	}
        color(A,min(B,M),L,M,2*P);
        color(max(A,M),B,M,R,2*P+1);
        board[P] = (board[2*P]|board[2*P+1]);
    }
    //printf("[%d, %d) -> %d\n", L,R,board[P]);
}

int count(int A,int B,int L,int R,int P){
    if(A>=B || L>=R)
    	return 0;
    else if(uniform[P] || (L==A && R==B))
    	return board[P];
    int M=(L+R+1)/2;
    int lr=count(A,min(B,M),L,M,2*P);
    int rr=count(max(A,M),B,M,R,2*P+1);
    return lr|rr;
}

int main(){
    int L,T,A,B,oper;
    while(-1!=scanf("%d%d%d",&L,&T,&oper)){
    C=1;
    color(1,L+1,1,L+1,1);
    while(oper--){
        char cmd[10];
        scanf("%s%d%d",cmd,&A,&B);
        if(A>B)swap(A,B);
        if(cmd[0]=='C') 
            scanf("%d",&C), color(A,B+1,1,L+1,1);
        else printf("%d\n", __builtin_popcount(count(A,B+1,1,L+1,1)));
    }
    }
}
