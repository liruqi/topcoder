#include <iostream>
using namespace std;

const int maxn=10;
int N;
bool M[maxn][maxn];	//mine
bool T[maxn][maxn];	//touched

bool valide(int x, int y)
{
 	return (x>=0 && x<N && y>=0 && y<N);
}

char Count(int x, int y)
{
 	char cnt='0'; 
 	if(valide(x-1, y-1)) if(M[x-1][y-1]) cnt++; 
	if(valide(x-1, y))   if(M[x-1][y])   cnt++; 
	if(valide(x-1, y+1)) if(M[x-1][y+1]) cnt++; 
 	if(valide(x, y-1))   if(M[x][y-1])   cnt++; 
 	if(valide(x, y+1))   if(M[x][y+1])   cnt++; 
 	if(valide(x+1, y-1)) if(M[x+1][y-1]) cnt++; 
	if(valide(x+1, y))   if(M[x+1][y])   cnt++; 
	if(valide(x+1, y+1)) if(M[x+1][y+1]) cnt++; 
 	return cnt;
}

bool MineTouched()
{
 	int i,j;
	for(i=0; i<N; i++)
	for(j=0; j<N; j++) 
	if(M[i][j] && T[i][j])
	{
//        cout<<"MineTouched! "<<i<<' '<<j<<endl;
	    return true;	    
	}
//	cout<<"MineUnTouched!"<<endl;
	return false;    
}
int main()
{
 	int i, j;
 	char c;
 	cin>>N;
 	for(i=0; i<N; i++)
 	for(j=0; j<N; j++){
 	cin>>c; M[i][j]=(c=='.'?0:1);
	}
	for(i=0; i<N; i++)
 	for(j=0; j<N; j++){
 	cin>>c; T[i][j]=(c=='.'?0:1);
	}
	if(MineTouched())
	{
	for(i=0; i<N; i++){
	 	for(j=0; j<N; j++){
			if(M[i][j])
			    c='*';
			else 
			    c=(T[i][j] ? Count(i, j):'.');
			cout<<c;
	    }
	    cout<<endl;
	}
    }
    else {
	for(i=0; i<N; i++){
	 	for(j=0; j<N; j++){
			cout<<(T[i][j] ? Count(i, j):'.');
	    }
	    cout<<endl;
	}
	}
	system("pause");
    return 0;
}
