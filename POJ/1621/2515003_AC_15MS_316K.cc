// team1 lexpegzmmdrp

#include <iostream>
using namespace std;

int ds(int n){
    int c=0;
    while(n)
    c++, n/=10;
    return c;
}

int main()
{
    int cnt, n, i, tc=1, x, a[110];
    while(cin>>n && n>0){
        for(i=n;i>=0;i--) cin>>a[i]; cin>>x;
        cnt=0;
        for(i=n;i>=0;i--)
            cnt+=a[i]*((i&1)?x:1);
        cout<<"Polynomial "<<(tc++)<<": "<<cnt;
        cnt=1+2*n-1;
        for(i=n-1;i>=0;i--)
            if(a[i]){
                  cnt+=ds(a[i])+1;
            }
            
        cout<<" "<<cnt<<endl;
    }
}
/*
3 1 0 1 11 1
3 1 0 2 11 -1
0 0
*/
