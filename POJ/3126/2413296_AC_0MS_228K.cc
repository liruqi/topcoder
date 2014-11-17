#include <iostream>
#include <cstring>

using namespace std;
#define maxn 10000

bool P[maxn], F[maxn];
int sour,dest;
void init(){
    int i,j;
    memset(P,1,maxn);
    P[0]=P[1]=0;
    for(i=2;i*i<maxn;i++) if(P[i])
    for(j=i*i;j<maxn;j+=i)
        P[j]=0;
}

struct que{
    int pl, pn;
}pp[5000], tmp;
int head, tail;

void enque(int l, int n){
    pp[tail].pl=l;
    pp[tail].pn=n;
    tail++;
}

void deque(struct que &t){
	t.pl=pp[head].pl;
	t.pn=pp[head].pn;
    head++;
}

int pstk[50],ptop;

void adjPrime(int p){
	ptop=0;
	//cout<<"find adj primes for "<<p<<endl;
    int i,dt[10]={1,10,100,1000,10000,100000};
    for(i=0;i<4;i++){
        int d=(p%dt[i+1])/dt[i];
        int t=p-d*dt[i];
        //cout<<t<<' '<<d<<endl;
        for(int j=(i==3?1:0);j<10;j++) if(j!=d)
        {
            int tp=t+j*dt[i];
            if(!F[tp] && P[tp]) {
                pstk[ptop++]=tp;
                F[tp]=1;
            }
        }
    }
    /*
    for(i=0;i<ptop;i++)
    {
        cout<<pstk[i]<<" ";
    }
    cout<<endl;
	getchar();
	*/
}

int bfs()
{
    if(sour==dest) return 0;
	head=0;
	tail=0;
    enque(0,sour);
    while(head<tail){
        deque(tmp);
		adjPrime(tmp.pn);
        for(int i=0;i<ptop;i++){
            enque(tmp.pl+1,pstk[i]);
            if(pstk[i]==dest)
                return tmp.pl+1;
        }
    }
    return -1;
}

int main()
{
    int N,cnt;
    init();
    cin>>N;
    
    while(N-- && cin>>sour>>dest)
    {
		memset(F,0,maxn);
        cnt=bfs();
        if(cnt<0) 
            cout<<"Impossible"<<endl;
        else 
            cout<<cnt<<endl;
    }
    
    return 0;
}

/*
3
1033 8179
1373 8017 
1033 1033
*/
