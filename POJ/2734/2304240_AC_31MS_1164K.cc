#include <iostream>

using namespace std;

int row,col;
char A[1001][1001];
int Q[100][2], K[100][2], P[100][2];
int D[8][2]={{1, 0}, {1, 1}, {0, 1}, {-1, 1}, 
             {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
int E[8][2]={{2,1},{1,2},{-1,2},{-2,1},
             {-2,-1},{-1,-2},{1,-2},{2,-1}};

void clear()
{
    for(int i=1; i<=row; i++)
    for(int j=1; j<=col; j++)
    A[i][j]=0;
}
int valid(int r, int c){
    if(r>row || r<1) return 0;
    if(c>col || c<1) return 0;
    return 1;
}

int count(){
    int cnt=0;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
        if(A[i][j]==0) cnt++;
        //putchar(A[i][j]);
        }
        //putchar(10);
    }
    return cnt;
}
int main()
{

    int qun, knt, pan, i, j, tc=1;
    while(cin>>row>>col && row && col){
        clear();
        cin>>qun;   //read queens
        for(i=0; i<qun; i++){
            cin>>Q[i][0]>>Q[i][1];
            A[ Q[i][0] ][ Q[i][1] ] = 'b';
        }
        cin>>knt;
        for(i=0; i<knt; i++){
            cin>>K[i][0]>>K[i][1];
            A[ K[i][0] ][ K[i][1] ] = 'b';
        }
        cin>>pan;
        for(i=0; i<pan; i++){
            cin>>P[i][0]>>P[i][1];
            A[ P[i][0] ][ P[i][1] ] = 'b'; 
        }
        
        //find the dangerous positions caused by queen
        for(i=0; i<qun; i++){
            int r=Q[i][0], c=Q[i][1];
            int rt, ct, di;
            for(di=0; di<8; di++){
                rt=r+D[di][0];
                ct=c+D[di][1];
                for(; valid(rt, ct) && A[rt][ct]!='b'; rt+=D[di][0], ct+=D[di][1])
                    A[rt][ct]='d';
            }
        }
        
        for(i=0; i<knt; i++){
            int r=K[i][0], c=K[i][1];
            int rt, ct, di;
            for(di=0; di<8; di++){
                rt=r+E[di][0];
                ct=c+E[di][1];
                if(valid(rt, ct) && !A[rt][ct])
                    A[rt][ct]='d';
            }
        }
        
        printf("Board %d has %d safe squares.\n", tc++, count());
    }
    return 0;
}
