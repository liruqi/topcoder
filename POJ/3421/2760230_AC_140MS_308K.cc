#include <iostream>
using namespace std;

#define maxn 21
typedef long long llg;
llg X;
int e[100],top;
llg fac[maxn];
int sol(){
	llg i,sum=0;
	top=0;memset(e,0,sizeof(e));
	for(i=2;i*i<=X;i++)if(X%i==0){
		do{
			e[top]++;
			X/=i;
		}while(X%i==0);
		sum+=e[top];
		top++;
	}
	if(X>1)
		e[top++]=1,sum++;
	llg cnt=fac[sum];
	for(i=0;i<top;i++)
		cnt/=fac[e[i]];
	cout<<sum<<' '<<cnt<<endl;
}

void init(){
	int i;
	fac[0]=1;
	for(i=1;i<maxn;i++)fac[i]=fac[i-1]*i;
}

int main()
{
	init();
	while(cin>>X) 
		sol();
	return 0;
}
