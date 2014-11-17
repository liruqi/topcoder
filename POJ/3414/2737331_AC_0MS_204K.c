#include<stdio.h>
#define maxn 101

int min(int a,int b){return a<b?a:b;}
char vst[maxn][maxn];
int A,B,C;
int qa[maxn*maxn], qb[maxn*maxn], head, tail;
int opr[maxn*maxn], pre[maxn*maxn], stk[maxn*maxn], top;
/*
1: fill 1
2: fill 2
3: drop 1
4: drop 2
5: pour 1->2
6: pour 2->1
*/

int bfs(){
    int ex;
    
    head=0;
    tail=1;
    qa[0]=qb[0]=0;
    vst[0][0]=1;
    while(head<tail){
        int ta=qa[head];
        int tb=qb[head];
        //printf("1: %d -- 2: %d\n",ta, tb);
        if(ta==C||tb==C) return 1;
        
        pre[tail]=head;
        opr[tail]=1;
        if(!vst[A][tb])
        {
            qa[tail]=A;
            qb[tail]=tb;
            tail++;
            vst[A][tb]=1;
        }
        
        pre[tail]=head;
        opr[tail]=2;
        if(!vst[ta][B]){
            qa[tail]=ta;
            qb[tail]=B;
            tail++;
            vst[ta][B]=1;
        }
        
        pre[tail]=head;
        opr[tail]=3;
        if(!vst[0][tb]){
            qa[tail]=0;
            qb[tail]=tb;
            tail++;
            vst[0][tb]=1;
        }
        
        pre[tail]=head;
        opr[tail]=4;
        if(!vst[ta][0]){
            qa[tail]=ta;
            qb[tail]=0;
            tail++;
            vst[ta][0]=1;
        }
        
        pre[tail]=head;
        opr[tail]=5;
        ex = min(ta, B-tb);//pour a->b
        if(!vst[ta-ex][tb+ex]){
            qa[tail]=ta-ex;
            qb[tail]=tb+ex;
            tail++;
            vst[ta-ex][tb+ex]=1;
        }
        
        pre[tail]=head;
        opr[tail]=6;
        ex = min(A-ta, tb);
        if(!vst[ta+ex][tb-ex]){
            qa[tail]=ta+ex;
            qb[tail]=tb-ex;
            tail++;
            vst[ta+ex][tb-ex]=1;
        }
        head++;
    }
    return 0;
}

void findpath(){
    top=0;
    int u=head, i;
    while(u!=0){
        stk[top++]=u;
        u=pre[u];
    }
    printf("%d\n",top);
    for(i=top-1;i>=0;i--){
        u=stk[i];
        switch(opr[u]){
            case 1:
                puts("FILL(1)");
                break;
            case 2:
                puts("FILL(2)");
                break;
            case 3:
                puts("DROP(1)");
                break;
            case 4:
                puts("DROP(2)");
                break;
            case 5:
                puts("POUR(1,2)");
                break;
            case 6:
                puts("POUR(2,1)");
                break;
        } 
    } 
}

int main()
{
    scanf("%d%d%d",&A,&B,&C);
    if( bfs() )
        findpath();
    else 
        puts("impossible");
    scanf("%*d");
}
