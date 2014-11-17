#include <iostream>
using namespace std;
int R[100],C[100];
int N,column,row;
int rv,cv;
bool parity(){
    int i;
    row=0; 
	column=0;
    for(i=0; i<N;i++){
        R[i]%=2;
        C[i]%=2;        
    }
    for(i=0; i<N;i++){
        if(R[i]){
			row++;rv=i;
		}
		if(C[i]){
			column++;cv=i;
		}	
    }
    if(row==0 && column==0)
	    return true;
    return false;
}
int main()
{
    int i,j,t;
    while(cin>>N && N){
		memset(R,0,sizeof(R));
		memset(C,0,sizeof(C));
        for(i=0; i<N;i++)
		for(j=0; j<N; j++){
	   		cin>>t;
	   		R[i]+=t;C[j]+=t;
        }
        if(parity())
	        cout<<"OK"<<endl;
        else if(row==1 && column==1)
            cout<<"Change bit ("<<rv+1<<","<<cv+1<<")"<<endl;
        else 
	        cout<<"Corrupt"<<endl;
    }
    return 0;
}
