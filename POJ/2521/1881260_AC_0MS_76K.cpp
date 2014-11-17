#include<iostream.h>
int main(void)
{
    int N,M,P,C;
    while(cin>>N>>M>>P>>C)
    {
        if(N==0 && M==0 && P==0 && C==0)break;
        cout<<(N+P-M)<<endl;
    }
    return 0;
}