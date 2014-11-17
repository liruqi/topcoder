#include <iostream>
using namespace std;

int A[200];
int main()
{
    int n, mx, mn,s;
    while(cin>>n){
        if(!n) return 0;
        cin>>A[0];
        mx=mn=A[0];
        s=A[0];
        for(int i=1;i<n;i++){
            cin>>A[i];
            s+=A[i];
            mx<?=A[i];
            mn>?=A[i];
        }
        
        s-=(mx+mn);
        int ans=s/(n-2);
        cout<<ans<<endl;
    }
}
