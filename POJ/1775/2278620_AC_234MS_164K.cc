#include <iostream>
using namespace std;
int A[10];
void init(){
    A[0]=1;
    for(int i=1; i<10; i++)
    A[i]=A[i-1]*i;
}
bool ok(int n){
    int i=9;
    if(!n) return 0;
    for(; i>=0; i--)
        if(n>=A[i]){
            n-=A[i];
        }
    
    return n==0;
}

int main()
{
    int n;
    init();
    while(cin>>n && n>=0){
        puts(ok(n)?"YES":"NO");
    }
    return 0;
}

