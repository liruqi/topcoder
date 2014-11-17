#include<iostream>
#include <algorithm>
using namespace std;

int fi[1100];

int euler(int n){
    int i,a=n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            a-=a/i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) a-=a/n;
    return a;
}

void init(){
    int i,j;
    for(fi[1]=3, i=2;i<1001;i++)
        fi[i]=fi[i-1]+2*euler(i);
}

int main()
{
    int i, t, n;
    /*
    while(
    scanf("%d", &t))
        cout<<euler(t)<<endl;
        */
        scanf("%d", &t);
    init();
    for (i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        printf("%d %d %d\n", i, n, fi[n]);
    }
    return 0;
}
