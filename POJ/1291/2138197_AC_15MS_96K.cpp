#include <iostream.h>
int max(int x, int y) {return x>y?x:y;}
const int Max=1001;
bool consistant, T[Max];
int A[Max], B[Max], C[Max], S[Max], N;
void init()
{
 	consistant=1; 
 	for(int i=0; i<=N; i++)
 	{
	    A[i]=i; 
	    C[i]=0;
  		S[i]=0;
		T[i]=1;
	}
}

void root(int x)
{
 	bool rt=1;
	int n=x;
	while(A[n]!=n) {
		rt = !(rt^T[n]);
		n = A[n];
	}
	A[x]=n; T[x]=rt;
}

void uniSet(int x, int y, bool tof)
{
 	root(x); root(y);
 	if(A[x] == A[y])
 	{
	 	if(tof == T[x] ^ T[y])
		    consistant=0;	
    }
    else {
		bool flag = !(T[x] ^ T[y]);
		T[A[x]]=!(flag^tof);
		A[A[x]]=A[y];
	}	  
}


int main()
{
 	char str[8];
 	int i;
 	
 	while(cin>>N && N)
 	{
		init();
		for(i=1; i<=N; i++)
		{
		 	cin>>str>>B[i]>>str>>str;
		 	uniSet(i, B[i], (str[0]=='f')?0:1);
	    }
	    if(consistant) {
			for(i=1; i<=N; i++){
				root(i);
				S[A[i]]++;
				if(T[i])
				    C[A[i]]++;
			}  
			for(i=1; i<=N; i++)
			 	C[0]+=max(C[i], S[i]-C[i]);
			cout<<C[0]<<endl;
		}
		else cout<<"Inconsistent"<<endl;
	}
}

