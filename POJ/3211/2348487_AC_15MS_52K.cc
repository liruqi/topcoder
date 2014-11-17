#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

char color[10][12];
//list <int> wct[10];
bool A[100000];
int B[10][100],C[10];
int M,N;

int clrID(char *str){   // 0,1...M-1
    for(int i=0; i<M; i++)
    if(strcmp(str, color[i])==0)
		return i;
    return -1;
}

int knapsack(int n){
    int sum=0, i, j;
    for(i=0; i<C[n]; i++)
        sum+=B[n][i];
    
    memset(A,0,sum/2+1);
    A[0]=1;
    int cnt=0;
    for(i=0; i<C[n]; i++){
        for(j=sum/2 - B[n][i]; j>=0; j--)
        if(A[j]) A[j+ B[n][i]]=1;
    }
    for(i=sum/2; !A[i]; i--);
    return sum-i;
}

int main()
{
    int i,j,id;
	char iclr[12];
	while(EOF != scanf("%d%d",&M,&N) && M>0){
        memset(C,0,40);
		for(i=0; i<M; i++){
			scanf("%s", color[i]);
		} 
		for(i=N; i; i--){
			scanf("%d %s",&j,iclr);
			id=clrID(iclr);
			//wct[id].push_back(j);
			B[id][C[id]]=j;
			C[id]++;
		}
		int cnt=0;
		for(i=0; i<M; i++){
			cnt+=knapsack(i);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
