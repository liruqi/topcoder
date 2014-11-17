#include <iostream>
using namespace std;
bool A[100][100];
int N,column,row;
int rv,cv;
bool parity(){
    int i,j,cnt;
    row=0; column=0;
    for(i=0; i<N;i++){
        cnt=0;
        for(j=0; j<N; j++) cnt+=A[i][j];
        if(cnt%2) {
            row++;rv=i;
       }
    }
    for(i=0; i<N;i++){
        cnt=0;
        for(j=0; j<N; j++) cnt+=A[j][i];
        if(cnt%2) {
            column++;cv=i;
        }
    }
    if(row==0 && column==0)return true;
    return false;
}
int main()
{
    int i,j;
    while(cin>>N && N){
       for(i=0; i<N;i++)for(j=0; j<N; j++) cin>>A[i][j];
       if(parity()) 
	       cout<<"OK"<<endl;
       else if(row==1 && column==1)
           cout<<"Change bit ("<<rv+1<<","<<cv+1<<")"<<endl;
       else 
	       cout<<"Corrupt"<<endl;
    }
    return 0;
}
