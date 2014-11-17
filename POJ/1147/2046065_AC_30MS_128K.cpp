#include<iostream>
using namespace std;
#define Max 3010
//#define debug
int Nxt[Max],N;
bool lc[Max], r[Max];

int main()
{
	int i,j,no0=0;
	cin>>N;
	for(i=1; i<=N; i++) {
		cin>>lc[i];
		if(!lc[i]) no0++;
	}
	j=1;
	for(i=1; i<=no0;)
		for(; j<=N; j++)
			if(!lc[j]) {
				Nxt[i++]=j++;
				break;
			}
	j=1;
	for(i=no0+1; i<=N;)
		for(; j<=N; j++)
			if(lc[j]) {
				Nxt[i++]=j++;
				break;
			}
	#ifdef debug
	for(i=1; i<=N; i++)
		cout<<lc[i]<<" ";
	cout<<endl<<no0<<"---"<<no1<<endl;
	cout<<"---Next---"<<endl;
	for(i=1; i<=N; i++)
		cout<<Nxt[i]<<" ";
	cout<<endl;
	#endif
	
	for(i=1,j=Nxt[i]; i<=N; i++,j=Nxt[j])
		cout<<lc[j]<<" ";
	cin>>i;	
	return 0;
}
