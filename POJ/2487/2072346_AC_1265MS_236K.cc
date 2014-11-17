#include <iostream>
#define Max 10001
using namespace std;

int C[Max];
int main(){
	int T,N,M,i,t,j=1;
	cin>>T;
	while(T--){
		int mt=0, tot=0;
		cout<<"Scenario #"<<j++<<":"<<endl;
		cin>>M>>N;
		memset(C, 0, 10000*sizeof(C[0]));
		for(i=0; i<N; i++){
			cin>>t;
			C[t]++;
			if(t>mt) mt=t;
		}
		for(i=mt; i>0; i--) if(C[i]){
//			cout<<i<<" -> "<<C[i]<<endl;
			M-=i*C[i];
			tot+=C[i];
			if(M<=0) break;			
		}
		if(M<=0){
			tot+=M/i;
			cout<<tot<<endl<<endl;
		}
		else
			cout<<"impossible"<<endl<<endl;
	}
	return 0;
}

