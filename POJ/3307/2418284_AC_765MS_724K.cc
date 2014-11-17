#include <iostream>
#include <algorithm>
using namespace std;
long long vn[1000000],v1,v2,v3,v4;
#define X 1e18
int main(){
    int T,N,top=1,p[5]={1,2,3,5,7};
    for(v1=1;v1<X;v1*=p[1])
        for(v2=v1;v2<X;v2*=p[2])
            for(v3=v2;v3<X;v3*=p[3])
                for(v4=v3;v4<X;v4*=p[4])
                    vn[top++]=v4;
    sort(vn,vn+top);
    cin>>T;
    while(cin>>N) cout<<vn[N]<<endl;
}
