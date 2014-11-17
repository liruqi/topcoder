#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void *arg1,const void *arg2)
{
	return *((int *)arg1)-*((int *)arg2);
}

int main()
{
	int N,i,K,q;
	char c[4];
	cin>>N;
	int *d=new int[N];
	for(i=0;i<N;i++)
		cin>>d[i];
	qsort(d,N,sizeof(int),compare);
	cin>>c;

	cin>>K;
	for(i=0;i<K;i++)
	{
		cin>>q;
		cout<<d[q-1]<<endl;
	}
	delete [] d;
}
