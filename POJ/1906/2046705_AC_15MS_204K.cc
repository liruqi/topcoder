#include <iostream>
using namespace std;
bool A[100];

void pow3(int m){
	short bi[100];
	int len=1, carry=0,i;
	bi[1]=1;
	while(m--){
		for(carry=0,i=1; i<=len; i++)
		{
		 	 bi[i]*=3;
		 	 bi[i]+=carry; 		 	 
		 	 carry=bi[i]/10;
		 	 bi[i]%=10;
		}
		if(carry>0) {
			len++;
			bi[len]=carry;
		}
    }
	for(i=len;i>0;i--)
		cout<<bi[i];
}

int main()
{
	long long n,i,j;
	while(cin>>n && n){
		n--;
		j=n;
		for(i=0;j ;i++){
			A[i]=j-(j/2)*2;
			j=j>>1;
		}
		j=i;
		cout<<"{ ";
		for(i=0; i<j ; i++) if(A[i])
		{	
			pow3(i);
			i<j-1?cout<<", ":cout<<" ";
		}
		cout<<"}"<<endl;	
	}
	
	return 0;
}
