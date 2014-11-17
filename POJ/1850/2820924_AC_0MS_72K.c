#include <stdio.h>
#include <string.h>
#define ML 12
char str[ML];
int num[ML];
int C[30][30];
int Comb(int n,int k){
	if(k<0||k>n)return 0;
	if(k==0||k==n)return 1;
	if(C[n][k]>=0) return C[n][k];
	return (C[n][k]=Comb(n-1,k-1)+Comb(n-1,k));
}

void init(){
	int i;
	memset(C,-1,sizeof(C));
	num[0]=1;
	for(i=1;i<ML;i++){
		num[i]=num[i-1]+Comb(26,i);
        //printf("%d\n",num[i]);
    }
}

int solve(){
	int sl = strlen(str);
	int i,j;
	int ret = num[sl-1];
	for(i=1;i<sl;i++)
		if(str[i-1]>=str[i])
			return 0;
	
	for(i=0;i<sl;i++){
		j=str[i]-'a';
		for(j--;j>=(i==0?0:str[i-1]-'a'+1);j--){
            ret += Comb(25-j,sl-i-1);
        }
	}
	return ret;
}
int main(){
	init();
	gets(str);
	printf("%d\n",solve());
}
