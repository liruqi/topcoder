#include <iostream>
using namespace std;
#define	MAXT 1100
#define MAXN 110
#define MOD 1000000

int T,A,S,E;
int Cb[MAXT*MAXN], Bk[MAXT*MAXN];
int Ct[MAXT];
int SumUp(int lt,int rt){
	if(lt<=0)return Bk[rt];
	return (Bk[rt]-Bk[lt-1]+MOD)%MOD;
}

int main(){
	int i,j,k;
	cin>>T>>A>>S>>E;
	for(i=A;i;i--){
		cin>>j;
		Ct[j]++;
	}
	memset(Cb,0,sizeof(Cb));
	Bk[0]=Cb[0]=1;
	int cs=0;
	for(i=1; i<=T; i++){
		cs+=Ct[i];
		for(j=1;j<=cs;j++)
			Bk[j]=(Bk[j-1]+Cb[j])%MOD;
		for(j=0;j<=cs;j++){
			Cb[j]=SumUp(j-Ct[i],j);
        }
	}
	for(j=1;j<=cs;j++)
	Bk[j]=(Bk[j-1]+Cb[j])%MOD;
	cout<<SumUp(S,E)<<endl;
	return 0;
}
