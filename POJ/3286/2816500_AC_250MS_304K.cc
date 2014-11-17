#include <iostream>
using namespace std;
typedef long long llg;

llg count(llg n){
    llg i=10,j, ret=1;
    if(n<0) return 0;
    for(;i<=n;i*=10){
        j=i/10;
        if(n/j%10){
            ret += (n/i)*j;
        }
        else {
            ret += (n/i-1)*j;
            ret += n%j + 1;
        }
    }
    return ret;
    
}

int main(){
    llg m,n;
    while(cin>>m>>n && m>=0){
        cout<<(count(n)-count(m-1))
            <<endl;
    } 
    return 0;
}    