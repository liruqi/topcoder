#define maxn 40000
#include <iostream>
using namespace std;

bool P[maxn];
int F[40], nof;
void iniPrime(){
	int i, j;
	memset(P, 0xff, sizeof(P));
	P[0]=P[1]=0;
	for(i=2; i<maxn; i++)
		for(j=i*i; j<maxn; j+=i)
			P[j]=false;
}

int main()
{
    int n,m,i;
    iniPrime();
    while(cin>>m&&m>0){
        nof=0;
        n=m;
        for(i=2;i<=n&&i<maxn&&n>1;i++) 
            if(P[i]&&n%i==0)
            {
                F[nof++]=i;
                while(n%i==0)
                    n/=i;
            }
        if(n>1) F[nof++]=n;
        n=m;
        for(i=0;i<nof;i++)
            n-=n/F[i];
        cout<<n<<endl;
    }
    return 0;
}
