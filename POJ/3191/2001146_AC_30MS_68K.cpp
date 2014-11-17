#include <iostream.h>
bool f[32];int main(){int n,i;cin>>n;if(!n){cout<<'0';return 0;}for(i=0; n; i++,n /= -2){if(n>0) {if(n%2)f[i]=1;else f[i]=0;}else {if(n%2) {f[i]=1;n--;}else f[i]=0;}}if(!f[i]) i--;for(;i>=0;i--)cout<<f[i];return 0;}
