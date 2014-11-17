#include <iostream>
#define MaxN 64
using namespace std;

int D[MaxN],target;
int Q[MaxN],front,rear;
bool Vstd[MaxN];
void Init()
{
 	memset(Vstd, 0, sizeof(Vstd)); 
 	memset(D, 0, sizeof(D)); 
	front=0;
	rear=0;
}
void EnQ(int n)
{
	Q[rear++]=n;
}
int DeQ()
{
	return Q[front++];
}
bool NotEmpty()
{
	return (rear>front);
}

int BFS(int n)
{
	int x,y,t;
	if(n==target)
		return 0;
	Vstd[n]=1;
	EnQ(n);
	
	while(NotEmpty()) {
		n=DeQ();x=n%8; y=n/8;
		if(n==target) {
		  	return D[n];
		}

		if(x+2<8)
		{
			t=x+2 + (y+1)*8;
			if(y+1<8 && !Vstd[t]) {
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
			t=x+2 + (y-1)*8;
			if(y-1>=0 && !Vstd[t]) {
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
		}
		if(x+1<8) {
			t=x+1 + (y+2)*8;
			if(y+2<8 && !Vstd[t]) {				
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
			t=x+1 + (y-2)*8;
			if(y-2>=0 && !Vstd[t]) {
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
		}
		if(x-1>=0) {
			t=x-1 + (y+2)*8;
			if(y+2<8 && !Vstd[t]) {				
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
			t=x-1 + (y-2)*8;
			if(y-2>=0 && !Vstd[t]) {
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
		}
		if(x-2>=0) {
			t=x-2 + (y+1)*8;
			if(y+1<8 && !Vstd[t]) {				
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
			t=x-2 + (y-1)*8;
			if(y-1>=0 && !Vstd[t]) {				
				EnQ(t);
				Vstd[t]=1;
				D[t]=D[n]+1;
			}
		}
	}
	return 0;
}

int main()
{
	char c1,c2;
	int x1,y1,x2,y2;
	while (cin>>c1>>y1) {
		cout<<"To get from "<<c1<<y1;
		Init();
		cin>>c2>>y2;
		cout<<" to "<<c2<<y2<<" takes ";
		x1=c1-'a';
		x2=c2-'a';
		y1--;
		y2--;
		target=x2+y2*8;
		cout<<BFS(x1+y1*8)<<" knight moves."<<endl;
	}
	return 0;
}
