#include<stdio.h>
#include<list>
using namespace std;

#define maxn  100019

int N,K;
list<int> ht[maxn];
int ps[maxn][35];//prev sum
int prime[4]={3,5,7,11};

int hash(int p){
	int i, s=0;
	for(i=0;i<K;i++){
		s+=ps[p][i]*prime[i%4];
	}
	return s%maxn;
}

bool ident(int p, int q){
	int i;
	for(i=0;i<K;i++)
	    if(ps[p][i]!=ps[q][i])
	        return 0;
	return 1;
}

int main(){
	int i,j,len=0,tl,pos, t, minele;
	scanf("%d%d",&N,&K);
	ht[hash(0)].push_back(0);
	for(i=1;i<=N;i++){
		scanf("%d",&t);
		for(j=0;j<K;j++) {
			ps[i][j]=ps[i-1][j];
			if(t & (1<<j))
			    ps[i][j]++;
		}
		
		minele=0x7f7f7f7f;
		for(j=0;j<K;j++)
			if(ps[i][j]<minele)
				minele=ps[i][j];
		for(j=0;j<K;j++)
			ps[i][j]-=minele;
		
		pos=hash(i);
		
		tl=-1;
		for(list<int>::iterator it=ht[pos].begin(); it!=ht[pos].end(); ++it)
		if(ident(*it, i)){
			tl=i-(*it);
			break;
		}
		//printf(" *** tl = %d, len = %d\n",tl,len);
		if(tl>0)
		{
			if(len<tl) len=tl;
		}
		else
			ht[pos].push_back(i);
	}
	/*
	for(i=1;i<=N;i++){
	    for(j=0;j<K;j++)
	    printf(" %d",ps[i][j]);puts("");
	}
	*/
	printf("%d\n",len);
	scanf("%d",&t);
}
/*

7 3
7
6
7
2
1
4
2
*/
