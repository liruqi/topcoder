#include <iostream>
#include <string.h>
using namespace std;

void inv_prt(int x){
	if(x==0) return ;
	cout<<(x%10);
	inv_prt(x/10);
}

char A[11],B[11];
int main()
{
	int i, al, bl, cy, a, b;
	int N; cin>>N;
	
	while(N--){
        bool end0 = 0;
		cin>>A>>B;
		al=strlen(A);
		bl=strlen(B);
		cy=0;
		for(i=0; i<al || i<bl; i++)
		{
            a=(i<al)?(A[i]-'0'):0;
            b=(i<bl)?(B[i]-'0'):0; 
            if((a+b+cy)%10)
            {
                cout<<(a+b+cy)%10;
                end0=1;
            }
            else {
                if(end0)
                cout<<0;
            }
            cy = (a+b+cy)/10;
        }
        if(cy)
            cout<<1;
		cout<<endl;
	}
	return 0;
}
