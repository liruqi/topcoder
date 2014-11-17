#include <iostream>
using namespace std;
#define maxn 1000001
int EKG[maxn]={0, 1, 2};
int P[maxn];
//int C[maxn];
bool U[maxn];
int A[maxn];
int Q[maxn/10], qt, endf;

void
findEKG(int p){
    int i, j, k;
    int val=0x7fffffff, prev=EKG[p-1];
    int pf[30],pt=0;

    for(i=0;i<qt&&Q[i]<=prev;i++) if(prev%Q[i]==0){
        pf[pt]=Q[i];
        do{
            prev/=pf[pt];
        }while(prev%pf[pt] == 0);
        pt++;
    }
    if(prev>1) pf[pt++]=prev;

    for(i=0;i<pt;i++){
        for(j=pf[i]*P[pf[i]]; j<maxn; j+=pf[i], P[pf[i]]++)
            if(!U[j]){
                val<?=j;
                break;
            }
    }
	if(val!=0x7fffffff){
		EKG[p]=val;
		U[val]=1;
		A[val]=p;
	}
	else endf=p;
}

void
init(){
    int i,j,p;
    //memset(C,0,4*maxn);qt=0;
    for(i=0;i<maxn;i++) P[i]=1;
    for(i=2;i*i<maxn;i++) if(P[i]){
        Q[qt++]=i;
        for(j=i*i;j<maxn;j+=i){
            P[j]=0;
            //p=C[j]++;
        }
    }

    U[0]=U[1]=U[2]=1;
    A[1]=1; A[2]=2; 
    for(i=3;i<maxn&&!endf;i++){
        findEKG(i);
    }
}

int
main()
{
    int n;
    init();
    cin>>n;
    while(n>0){
        cout<<"The number "<<n
            <<" appears in location "<<A[n]
            <<"."
            <<endl;
            cin>>n;
    }
    return 0;
}