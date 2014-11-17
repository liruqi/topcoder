#include <iostream>
#include <algorithm>
#define mfw(x) ((x==3)?0:(x+1))
using namespace std;
const int maxp =(2<<18)+1;
bool Vd[maxp];
int Qu[maxp], head, tail;
int Mv[maxp],Pv[maxp];
int AC[10][10]={
    {0},
    {4, 1,2,4,5},
    {3, 1,2,3},
    {4, 2,3,5,6},
    {3, 1,4,7},
    {5, 2,4,5,6,8},
    {3, 3,6,9},
    {4, 4,5,7,8},
    {3, 7,8,9},
    {4, 5,6,8,9}
};
void enqu(int v, int move, int prv){
    Qu[tail++]=v;
    Vd[v]=1;
    Mv[v]=move;
    Pv[v]=prv;
}
int dequ(){
    return Qu[head++];
}

int trans(int sp, int move){
    int cp[10],i,j;
    for(i=1;i<10;i++)
    {
        cp[i]=sp%4;
        sp/=4;
    }
    for(i=1;i<=AC[move][0];i++){
        j=AC[move][i];
        cp[j]=mfw(cp[j]);
    }
    
    for(sp=0,i=1,j=1;i<10;i++,j*=4){
        sp+=cp[i]*j;
    }
    return sp;
}

void bfs(){
    while(head<tail){
        int sp=dequ();  //start point
        int i,j,np;     //new point
        for(i=1;i<=9;i++){
            np=trans(sp, i);
            if(!Vd[np])
                enqu(np, i, sp);
            if(np==0) return;
        }
    }
}

int ssm[maxp], stop;
int main()
{
    int val=0, t, i, j;
    for(i=0, j=1;i<9;i++, j*=4){
        cin>>t;
        val+=t*j;
    }
    head = tail = stop = 0;
    enqu(val,-1,-1);
    bfs();
    for(i=0;Pv[i]>=0;i=Pv[i]){
        ssm[stop++]=Mv[i];
    }
    for(i=stop-1;i>=0;i--)
        cout<<ssm[i]<<(i?" ":"\n");
    return 0;
}
