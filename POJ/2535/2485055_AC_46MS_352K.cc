#include <iostream>

using namespace std;

int R[101][101];
int S[101],H[101];
int N,P;
int main(){
    int i,j;
    cin>>N>>P;
    for(i=0;i<N;i++){
        cin>>R[i][0];
        S[i]=H[i]=R[i][0];
        for(j=1;j<P;j++){
            cin>>R[i][j];
            S[i]<?=R[i][j];
            H[i]>?=R[i][j];
        }
        //cout<<S[i]<<" "<<H[i]<<endl;
    }
    int cnt=0;
    for(j=0;j<P;j++){
        int sn=0, hn=0;
        for(i=0;i<N;i++){
            if(S[i]==R[i][j])
                sn++;
            if(H[i]==R[i][j]){
                hn++;
                break;
            }
        }
        if(hn==0 && sn*2>N) cout<<(cnt++?" ":"")<<j+1;
    }
    if(!cnt) cout<<0;
    cout<<endl;
    return 0;
}

