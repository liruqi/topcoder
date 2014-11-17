//1186

#include <iostream>
#include <list>
#define maxh 3375321
using namespace std;
typedef list<pair<int,int> > lit;
typedef lit::iterator lii;

int N,M,K[10],P[10],cnt;
lit ht[maxh];
int hash(int n){
    return n&0x2fffff;
}
int dat[2][maxh/100],top;
int dp[151][6];
int power(int b,int e){
    if(!dp[b][e])
        if(e<=1)dp[b][1]=b;
        else dp[b][e]=b*power(b,e-1);
    return dp[b][e];
} 

void insert(int p,int v){
    for(lii it=ht[p].begin();it!=ht[p].end();++it)if(it->first==v){it->second++;return;}
    ht[p].push_back(make_pair(v,1));
}    

void addHash(int d){
    int i,x,v,p;
    int *r=(int*)(dat+(d&1)), *w=(int*)(dat+((1+d)&1));
    if(d>=(N>>1)){
        for(i=0;i<top;i++)for(x=1;x<=M;x++)
            v=r[i]+K[d]*power(x,P[d]),p=hash(-v),insert(p,-v);//ht[p].push_back(-v);
    } 
    else {
        int nt=0;
        for(i=0;i<top;i++)for(x=1;x<=M;x++)w[nt++]=r[i]+K[d]*power(x,P[d]);
        top=nt;
        addHash(d+1);
    } 
}

void cntHash(int d){
    int i,x,v,p;
    int *r=(int*)(dat+(d&1)), *w=(int*)(dat+((1+d)&1));
    if(d>=N){
        for(i=0;i<top;i++)for(x=1;x<=M;x++){
            v=r[i]+K[d]*power(x,P[d]);
            p=hash(v);
            for(lii it=ht[p].begin(); it!=ht[p].end(); ++it)if(it->first==v){cnt+=it->second;break;}
        } 
    } 
    else {
        int nt=0;
        for(i=0;i<top;i++)for(x=1;x<=M;x++)w[nt++]=r[i]+K[d]*power(x,P[d]);
        top=nt;
        cntHash(d+1);
    }
} 
int main(){
    int i;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++){
        scanf("%d%d",K+i,P+i);
    }
    top=1;dat[1][0]=0;
    addHash(1);
    top=1;dat[(N/2+1)&1][0]=0;
    cntHash(N/2+1);
    printf("%d\n",cnt);
} 