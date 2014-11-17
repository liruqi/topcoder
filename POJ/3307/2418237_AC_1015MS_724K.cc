#include <iostream>
#include <algorithm>
using namespace std;
long long vn[1000000];
int top;
#define maxv 1e18
int main()
{
    int T,N;
    long long v1,v2,v3,v4;
    int p[5]={1,2,3,5,7};
    top=1;
    for(v1=1;v1<maxv;v1*=p[1])
        for(v2=v1;v2<maxv;v2*=p[2])
            for(v3=v2;v3<maxv;v3*=p[3])
                for(v4=v3;v4<maxv;v4*=p[4])
                    vn[top++]=v4;
    sort(vn,vn+top);
    cin>>T;
    while(T-- && cin>>N)
        cout<<vn[N]<<endl;
    return 0;
}
